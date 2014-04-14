// Boolean values if not defined
#ifndef TRUE
#define TRUE 1
#endif


#ifndef FALSE
#define FALSE 0
#endif

// Constants used when determining Directory Entry types
#define EOD 0
#define UNUSED 1
#define LFNAME 2
#define NFNAME 3
#define NDNAME 4 //Normal directory

// Global constants used by the FAT32 file system
#define BUFFER_SIZE 512
#define DIRENTRY_SIZE 32
#define FILENAME_SIZE 12
#define FILEDATA_SIZE 32
#define PARTITION_ENTRY_SIZE  16

#define FIRST_PARTITION_ENTRY 0x1BE

// Buffers used to temporarily save the obtained data
BYTE SectorBuffer[BUFFER_SIZE];
BYTE DirEntry[DIRENTRY_SIZE];

// Volume ID information
unsigned int16 BytesPerSector;
unsigned BYTE  SectorsPerCluster;
unsigned int16 NumberOfReservedSectors;
unsigned BYTE  NumberOfFATs;
unsigned int32 SectorsPerFAT;
unsigned int32 RootDirectoryFirstCluster;

// Information related to partitions and FAT table
unsigned int32 PartitionLBABegin;
unsigned int32 FatBeginLBA;
//unsigned int32 ClusterBeginLBA;
unsigned int32 DataBeginLBA;
unsigned int8  FAT16Offset;

// Variables used to store the position of current entry
// when reading directory contents.
unsigned int32 DirectoryCurrentCluster;
unsigned int32 DirectoryCurrentLBA;
unsigned BYTE DirectoryCurrentDirEntry;
unsigned int16 DirectoryCurrentSector;
unsigned BOOLEAN DirectoryOpened;
unsigned BOOLEAN EODReached;

// Variables used to store file information when reading
unsigned int32 FileCurrentCluster;
unsigned int32 FileCurrentLBA;
unsigned int16 FileCurrentSector;
unsigned int32 FileLengthCount;
unsigned int16 FileSectorPosition;
unsigned BOOLEAN FileOpened;

// File descriptor structure
typedef struct
{
   unsigned BYTE Name[FILENAME_SIZE];
   unsigned int8  Attributes;
   unsigned int32 FirstLBA;
   unsigned int32 Size;
   unsigned int32 FirstCluster;
} FILEDESCRIPTOR;

//A partition Entry structure
typedef struct
{   
   unsigned short IsValid;
   unsigned short IsFAT32;
   BYTE Type;
} PARTITIONENTRY;

// File data structure
typedef struct
{
   unsigned BYTE Buffer[FILEDATA_SIZE];
   unsigned int16 BytesRead;
   unsigned BOOLEAN EOF;
} FILEDATA;

PARTITIONENTRY pEntry;

// -- Start of Code Section -------------

BOOLEAN ReadSector(unsigned int32 lba)
{
   unsigned long i;
   
   mmc_open_block(lba);
   for (i = 0; i < BUFFER_SIZE; i++)
   {
      SectorBuffer[i] = spi_read(0xFF);
   }
   mmc_close_block();
   
   return TRUE;
}

void ReadDirEntry(BYTE num)
{
   // Calculate Directory Entry offset according to Directory Entry number
   unsigned int16 offset;
   unsigned int16 i;
   
   offset = (unsigned int16)num * DIRENTRY_SIZE;
   // Copy the Directory Entry data to the DirEntry vector in order to
   // analyze the data later
   for (i = 0; i < DIRENTRY_SIZE; i++)
   {
       DirEntry[i] = SectorBuffer[offset + i];
   }
}

BOOLEAN GetEntry(unsigned int16 startingPos)
{
   pEntry.IsValid = FALSE;

   //Partition must exists and be ACTIVE
   if (SectorBuffer[startingPos] != 0x80)
      return FALSE;
      
   pEntry.Type = SectorBuffer[startingPos + 4];
   
   if (pEntry.Type == 0x04 || pEntry.Type == 0x06 || pEntry.Type == 0x0E)
   {
      pEntry.IsFAT32 = FALSE;
      pEntry.IsValid = TRUE;
   }
   
   if (pEntry.Type == 0x0B || pEntry.Type == 0x0C)
   {
      pEntry.IsFAT32 = TRUE;
      pEntry.IsValid = TRUE;
   }
   
   if (!pEntry.IsValid)
      return FALSE;

   PartitionLBABegin = MAKE32(SectorBuffer[startingPos + 11], SectorBuffer[startingPos + 10], SectorBuffer[startingPos + 9], SectorBuffer[startingPos + 8]);
   
   return TRUE;
}

BOOLEAN FindFirstFATPartition()
{
   BYTE i;

   // Read the first Sector
   ReadSector(0);

   if (SectorBuffer[0x1FE] != 0x55 || SectorBuffer[0x1FF] != 0xAA) return FALSE;    //If no correct signature, return 
   
   pEntry.IsValid = FALSE;
   for (i = 0; i < 4; i++)
   {
      if (GetEntry(FIRST_PARTITION_ENTRY + (i * PARTITION_ENTRY_SIZE)))
         break;
   }
   
   //Worst case. No partitions entry. Asume that MBR is at Sector 0 and its a FAT32 image.
   if (!pEntry.IsValid)
   {
      // Look for the offset
      PartitionLBABegin = 0;
      pEntry.IsFAT32 = TRUE;
      pEntry.IsValid = TRUE;
   }

   return TRUE;
}

BOOLEAN ReadVolumeID()
{        
   // Read the first sector of the partition
   ReadSector(PartitionLBABegin);

   //Initial values
   FAT16Offset = 0;

   // If the signature is 0xAA55 we are in presence of a FAT volume
   if (SectorBuffer[0x1FE] != 0x55 || SectorBuffer[0x1FF] != 0xAA) return FALSE;    //If no correct signature, return 
       
   // Bytes per Sector
   BytesPerSector = MAKE16(SectorBuffer[0x0B + 1],SectorBuffer[0x0B]);

   // Sectors per Cluster
   SectorsPerCluster = SectorBuffer[0x0D];

   // Number of Reserved Sectors
   NumberOfReservedSectors = Make16(SectorBuffer[0x0E + 1],SectorBuffer[0x0E]);

   // Number of FATs
   NumberOfFATs = SectorBuffer[0x10];

   // Sectors per FAT    //differents in FAT16/32
   if (pEntry.IsFAT32)
   {
      SectorsPerFAT = MAKE32(SectorBuffer[0x24+3], SectorBuffer[0x24 + 2], SectorBuffer[0x24 + 1], SectorBuffer[0x24]);
   } else {
      SectorsPerFAT = MAKE16(SectorBuffer[0x16 + 1], SectorBuffer[0x16]);
      // FAT16 have an offset to calculate real ClusterBeginLBA
      FAT16Offset = ((unsigned int32)MAKE16(SectorBuffer[0x11 + 1], SectorBuffer[0x11]) * 32) / ((unsigned int32)BytesPerSector);
   }

   // Important zones CALCULUS:
   FatBeginLBA = PartitionLBABegin + ((unsigned int32)NumberOfReservedSectors);
   DataBeginLBA = FatBeginLBA + ((unsigned int32)(NumberOfFATs * SectorsPerFAT));

   // Root Directory First Cluster
   if (pEntry.IsFAT32)
   {
      RootDirectoryFirstCluster = MAKE32(SectorBuffer[0x2C + 3], SectorBuffer[0x2C + 2], SectorBuffer[0x2C + 1], SectorBuffer[0x2C]);  
   } else {
      //DataBeginLBA += 32;
      RootDirectoryFirstCluster = 2;
   }
   
   return TRUE;
}

unsigned int32 ComputeLBA(unsigned int32 clusternumber)
{
   // Compute the LBA number using the Cluster Number{
   return DataBeginLBA + ((clusternumber - 2) * ((unsigned int32)SectorsPerCluster));
}

BOOLEAN CheckIfEOD()
{
   // Check if the current directory entry (contained in the DirEntry vector)
   // correspond to the flag End Of Directory.
   if (DirEntry[0] == 0x00)
   {
       return TRUE;
   }
   else
   {
       return FALSE;
   }
}

BYTE GetAttib()
{
   // Get the Attributes byte from current Directory Entry
   return DirEntry[0x0B];
}

BOOLEAN CheckIfNormalFile()
{
   // Check if the Directory Entry corresponds to a Normal File Name
   BYTE attr;
   
   attr = GetAttib();

   attr <<= 4;
   if (attr == 0xF0)
   {
       // If not, it is a Long File Name entry
       return FALSE;
   }
   else
   {
       return TRUE;
   }
}

BYTE DetermineDirEntryType()
{
   // Determine the Directory Entry type
   if (CheckIfEOD())
   {
       // The Directory Entry is an End Of Directory flag
       EODReached = TRUE;
       return EOD;
   }
   else
   {
       // If not, we check the first byte to know if the entry is unused
       if (DirEntry[0] == 0xE5)
       {
           return UNUSED;
       }
       else
       {
           // If it is used, we check if the Directory Entry corresponds to a Normal File Name
           if (CheckIfNormalFile())
           {
               if(bit_test(GetAttib(),4)) return NDNAME;       //is a sub directory.
               return NFNAME;
           }
           else
           {
               return LFNAME;
           }
       }
   }
}

unsigned int32 GetFileSize()
{
   // Get the file size of the current Directory Entry
   return MAKE32(DirEntry[0x1C + 3], DirEntry[0x1C + 2], DirEntry[0x1C + 1], DirEntry[0x1C + 0]);
}

void GetFileName(BYTE * filename)
{
   // Get the 8+3 FAT32 short file name.
   // This function may be changed in other platforms and/or architectures
   // using the correct string functions.
   unsigned int8 i;
   
   for (i = 0; i < 8; i++)
   {
       filename[i] = DirEntry[i];
   }
   filename[8] = '.';
   for (i = 8; i < 11; i++)
   {
       filename[i + 1] = DirEntry[i];
   }
   
}

void GetDirName(BYTE * filename)
{
   // Get the 8 FAT32 short file name.
   // This function may be changed in other platforms and/or architectures
   // using the correct string functions.
   unsigned int8 i;
   
   for (i = 0; i < 11; i++)
   {
       filename[i] = DirEntry[i];
   }

   filename[i]='\0';

}

unsigned int32 GetFileFirstCluster()
{
   // Get the file first cluster using the current Directory Entry data
   return MAKE32(DirEntry[0x14 + 1], DirEntry[0x14], DirEntry[0x1A + 1], DirEntry[0x1A]);
}

unsigned int32 ReadFAT(unsigned int32 clusternumber)
{
   // This might be one of the most complicated functions in the entire FAT16/32
   // implementation. It computes the next cluster of a file/directory reading the
   // FAT table.

   // Calculate the sector number (after FAT LBA Begin) in which we can find
   // the cluster information we are looking for.
   
   unsigned int32 calc;
   unsigned int32 offset;
   unsigned int32 rest;
   unsigned int32 soff;
   
   calc = clusternumber / ((unsigned int32)BytesPerSector / 4);

   // Calculate the LBA of the sector containing the information
   offset = FatBeginLBA + calc;

   // Calculate the offset within the sector that has been read
   rest = clusternumber - (calc * ((unsigned int32)BytesPerSector / 4));
   soff = rest * 4;

   // Read the sector
   ReadSector(offset);
   // Read the next cluster number
   return MAKE32(SectorBuffer[soff + 3], SectorBuffer[soff + 2], SectorBuffer[soff + 1], SectorBuffer[soff]);
}

void OpenDirectory(unsigned int32 directorycluster)
{
   // Initialize the variables needed to follow the directory pointed by
   // the passed argument.
   DirectoryCurrentCluster = directorycluster;
   DirectoryCurrentLBA = ComputeLBA(DirectoryCurrentCluster);
   DirectoryCurrentDirEntry = 0;
   DirectoryCurrentSector = 0;

   EODReached = FALSE;
   DirectoryOpened = TRUE;
}

FILEDESCRIPTOR FindNextFile()
{
   // Define the variables that will be used
   FILEDESCRIPTOR thefile;
   BOOLEAN filefound;

   // Set initial values
   filefound = FALSE;
   
   thefile.Attributes = 0;
   thefile.FirstLBA = 0;
   thefile.FirstCluster = 0;
   thefile.Size = 0;

   // Read the next sector of the cluster
   ReadSector(DirectoryCurrentLBA);

   // If the directory has been opened with OpenDirectory
   if (DirectoryOpened)
   {
       // Follow the Directory Entries looking for files
       do
       {
           // Read the next directory entry
           ReadDirEntry(DirectoryCurrentDirEntry);

            switch (DetermineDirEntryType())
            {
               // If the directory entry is a Normal Directory Name
               case NDNAME:
                  // We are in presence of a sub directory, and we get its information
                  GetDirName(thefile.Name);
                  thefile.Attributes = GetAttib();
                  thefile.FirstCluster = GetFileFirstCluster();
                  thefile.FirstLBA = ComputeLBA(thefile.FirstCluster) + FAT16Offset;

                  // Read the last computed sector, to re-fill the SectorBuffer
                  // that could have been overwritten when obtaining file information.
                  //ReadSectorRelativeToPartition(DirectoryCurrentLBA);  ????

                  // Set the File Found flag
                  filefound = TRUE;
                  break;

               // If the directory entry is a Normal File Name
               case NFNAME:
                  // And the Attribute is 0x20
                  if (GetAttib() == 0x20)
                  {
                     // We are in presence of a file, and we get its information
                     GetFileName(thefile.Name);
                     thefile.Size = GetFileSize();
                     thefile.Attributes = GetAttib();
                     thefile.FirstCluster = GetFileFirstCluster();
                     thefile.FirstLBA = ComputeLBA(thefile.FirstCluster) + FAT16Offset;
                     
                     // Read the last computed sector, to re-fill the SectorBuffer
                     // that could have been overwritten when obtaining file information.
                     //ReadSectorRelativeToPartition(DirectoryCurrentLBA);  ?????
                     
                     // Set the File Found flag
                     filefound = TRUE;
                  }               
                  break;
            }
         
           // Increment the current Directory Entry index
           DirectoryCurrentDirEntry++;
           // If the Directory Entry index is greater than 15 (only 16
           // directory entries could be found into a sector)
           if (DirectoryCurrentDirEntry > 15)
           {
               // Reset the Directory Entry index
               DirectoryCurrentDirEntry = 0;

               // Increment the current sector index
               DirectoryCurrentSector++;
               // If the sector index is minor than the SectorsPerCluster
               if (DirectoryCurrentSector < SectorsPerCluster)
               {
                   // We move to the next sector
                   DirectoryCurrentLBA++;
               }
               // If not, we need to move to another cluster
               else
               {
                   // And we compute the next cluster first sector
                   DirectoryCurrentSector = 0;
                   DirectoryCurrentCluster = ReadFAT(DirectoryCurrentCluster);
                   DirectoryCurrentLBA = ComputeLBA(DirectoryCurrentCluster);
               }

               // Read the next sector computed before
               ReadSector(DirectoryCurrentLBA);
           }
       }
       // Do this until an EOD is found or the File Found flag is set
       while ((!CheckIfEOD()) && (!filefound));
   }

   // Return the File Descriptor
   return thefile;
}

void CloseDirectory()
{
   // Close the directory
   DirectoryOpened = FALSE;
}

void OpenFile(FILEDESCRIPTOR file)
{
   // Initialize the variables needed to follow the file pointed by
   // the passed File Descriptor.
   FileCurrentCluster = file.FirstCluster;
   FileCurrentLBA = ComputeLBA(FileCurrentCluster) + FAT16offset;
   FileCurrentSector = 0;
   FileLengthCount = 0;
   FileSectorPosition = 0;

   FileOpened = TRUE;
}

FILEDATA ReadFile(FILEDESCRIPTOR file, unsigned int32 count)
{
   // Define the variables that will be used
   FILEDATA data;
   unsigned int16 bytesread = 0;
   unsigned int16 i;

   // Set initial values and initialize the Buffer vector
   data.BytesRead = 0;
   data.EOF = TRUE;

   // Read the next file sector
   ReadSector(FileCurrentLBA);

   // If the file has been opened with OpenFile()
   if (FileOpened)
   {
       // Read 'count' bytes from the current file sector
       for (i = 0; i < count; i++)
       {
           // Increment the length count
           FileLengthCount++;
           // Compare the length count to the total file size
           if (FileLengthCount <= file.Size)
           {
               // We only read if we have not reached the total file size
               data.Buffer[i] = SectorBuffer[FileSectorPosition + i];
               // Count the bytes that have been read
               bytesread++;
           }
       }
       
       // Set the bytes read into the resulting FileData structure
       data.BytesRead = bytesread;

       // Set the current sector position in order to continue from there the next time
       FileSectorPosition += (unsigned int16)bytesread;

       // If the sector position is greater than the maximum sector size
       if (FileSectorPosition > (BUFFER_SIZE - 1))
       {
           // Reset the file sector position
           FileSectorPosition = 0;

           // Increment the current sector
           FileCurrentSector++;
           // If the current sector is minor than the Sectors Per Cluster
           if (FileCurrentSector < SectorsPerCluster)
           {
               // Move to the next sector of the cluster
               FileCurrentLBA++;
           }
           // If not, read the FAT looking for the next cluster
           else
           {
               // And then, compute the first cluster sector
               FileCurrentSector = 0;
               FileCurrentCluster = ReadFAT(FileCurrentCluster);
               FileCurrentLBA = ComputeLBA(FileCurrentCluster) + FAT16offset;
           }
           // Read the sector computer before
           ReadSector(FileCurrentLBA);
       }
       // If the sector position is greater than the sector buffer size
       else
       {
           // Check if the total file size has been reached
           if (FileLengthCount >= file.Size)
           {
               // Force an EOF (End of File)
               FileCurrentCluster = 0xFFFFFFFF;
           }
       }

       // If the current cluster is greater than 0xFFFFFFF8, we have an EOF
       if (FileCurrentCluster < 0xFFFFFFF8)
       {
           data.EOF = FALSE;
       }
       else
       {
           data.EOF = true;
       }
   }

   // Return the FileData structure
   return data;
}

void CloseFile()
{
   // Close the currently opened file
   FileOpened = FALSE;
}
