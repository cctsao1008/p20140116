#include "fattest.h"
#include "mmcdriver.h"
#include "fatdriver.h"

void main()
{
   unsigned int16 i;
   unsigned int16 j;
   unsigned int16 c;
   
   // Create a file descriptor
   FILEDESCRIPTOR fd;
   
   // Create a FileData structure
   FILEDATA data;
      
   set_tris_a(0x00);
   
   mmc_init();
   
   // Find the first FAT partition
   FindFirstFATPartition();
   
   printf("Partition LBA Begin: %lu\r\n", PartitionLBABegin);
   if (pEntry.IsValid)
   {
      if (pEntry.IsFAT32)
         printf("System is: FAT32\r\n");
      else
         printf("System is: FAT16\r\n");
   } else {
      printf("Memory format not FAT16 or FAT32\r\n");
   }
   
   // Read the Volume ID to get some information important for further calculations
   // If the function ReadVolumeID() returns True, it is a FAT32 volume.
   if (ReadVolumeID() == TRUE)
   {
       printf("Bytes per sector: %lu\r\n", BytesPerSector);
       printf("Sectors per cluster: %u\r\n", SectorsPerCluster);
       printf("Number of reserved sectors: %lu\r\n", NumberOfReservedSectors);
       printf("Number of FATs: %u\r\n", NumberOfFATs);
       printf("Sectors per FAT: %lu\r\n", SectorsPerFAT);
       printf("Root directory first cluster: %lu\r\n", RootDirectoryFirstCluster);
       printf("FAT begin LBA: %lu\r\n", FatBeginLBA);
       printf("Data begin LBA: %lu\r\n", DataBeginLBA+FAT16offset);
       printf("Root Directory LBA: %lu\r\n", ComputeLBA(RootDirectoryFirstCluster));
   
       printf("\r\n");
   
       // Open the root directory passing the Root Directory First Cluster
       // to the function OpenDirectory. You can open another directory
       // just passing its first cluster.
       OpenDirectory(RootDirectoryFirstCluster);

       // We move on through the directory looking for files. If we get some file with size
       // greater than zero, we can read it.
       //fd = FindNextFile();
       do
       {
           // Repeat the process until no more files are found
           fd = FindNextFile();
           if(bit_test(fd.Attributes,4))
           {
              printf("Dir:");
              for (i = 0; i < FILENAME_SIZE; i++)
              {
                  printf("%c", fd.Name[i]);
              }
              printf("\r\n");
              printf("First LBA: %lu\r\n", fd.FirstLBA);
              printf("First Cluster: %lu\r\n", fd.FirstCluster);
              printf("\r\n");
           }else{
             if(fd.Size > 0)
             {
                 // A file has been found and we display its name, size, first LBA sector, etc.
                 printf("File:");
                 for (i = 0; i < FILENAME_SIZE; i++)
                 {
                     printf("%c", fd.Name[i]);
                 }
                 printf("\r\n");
                 printf("Size: %lu bytes\r\n", fd.Size);
                 printf("First LBA: %lu\r\n", fd.FirstLBA);
                 printf("First Cluster: %lu\r\n", fd.FirstCluster);
                 printf("\r\n");
                 
                 printf("Showing file's first 32 bytes...\r\n\r\n");
                 
                 // Open the file obtained with FindNextFile
                 OpenFile(fd);
      
                 // Get some data in 32 bytes chunks. It is very important to use
                 // the FILEDATA_SIZE constant. You can change this constant to use
                 // another size that must be multiple of 2, like 1, 32, 64, 256, or 512.
                 // The maximum buffer size allowed is 512.
                 data = ReadFile(fd, FILEDATA_SIZE);
                  
                 // Show file's first 32 bytes
                 c = 0;
                 for (i = 0; i < 2; i++)
                 {
                     for (j = 0; j < 16; j++)
                     {
                        printf("%2X ", data.Buffer[c]);
                        c++;
                     }
                     printf("\r\n");
                 }
                 
                 // Close the opened file handlers
                 CloseFile();
                 
                 printf("\r\n");
             }
          }
       }while(!EODReached);
   
       // Close the directory handlers
       CloseDirectory();
   
       // Display a final message
       printf("No more files in root directory!\r\n");
   }
   
   while (TRUE);
}

