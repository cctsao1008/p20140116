Nano FAT Library created by Andres Olivares (andyolivares@gmail.com)
Version 1.2 (see CHANGELOG for details)

The driver is capable of reading a root directory and its
contents (sub-directories and files).

Files can be read in user selectable data chunk sizes that must
be multiples of 2. For example, data can be obtained in buffers
of 1, 2, 4, 8, 16, 32, 64, 128, 256 and 512 bytes.
The maximum buffer size allowed is 512 bytes. Any other buffer size
will produce junk data or may cause an infinite loop in the
program flow.

I'm 100% sure this driver implementation is not bug free, so if
you find something that could be a bug, please let me know.
If you are good enough to solve it for your own, please don't
forget to share the resulting code with me, so others could
benefit from it.
Also, I'm sure that the code can be optimized to get better
performance and/or a lower footprint. If you make any change
to the code, the same sharing policies mentioned before apply.
 
This code is provided as is with no warranties at all. Use this code
at your own risk.

The code provided is FREE FOR PERSONAL USE. If you need to use it
for commercial purposes please contact me in order to make some
agreement.

For more information of this code and other projects, please take
a look at my web site located at: http://www.andyolivares.com.
Finally, if you make some cool projects using this code, please let
me know to mention it on the web site. Thanks!

If you want to know more details of FAT32 file systems, please refer
to the article "Understanding FAT32 Filesystems" by Paul Stoffregen.
The article can be found at http://www.pjrc.com/tech/8051/ide/fat32.html

See the CHANGELOG for more information.
