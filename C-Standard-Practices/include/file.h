#ifndef STD_C_FILE_H_
#define STD_C_FILE_H_

#ifndef STDLIB_STDIO_INCLUDED
#define STDLIB_STDIO_INCLUDED
#include <stdio.h>
#endif // STDLIB_STDIO_INCLUDED

#ifndef STDLIB_STDLIB_INCLUDED
#define STDLIB_STDLIB_INCLUDED
#include <stdlib.h>
#endif // STDLIB_STDLIB_INCLUDED

typedef FILE*  File;
typedef FILE** FileHandle;

File openFile(const char *filename, const char *mode);

File createFile(const char *filename);

/** Function: void CloseFile(File *fileHandle)
 *  
 *  I'm using "File *fileHandle" for now, rather than "FileHandle fileHandle",
 *  because I'm not sure if using a completely different type that implcitly
 *  assumes a new level of indirection might be too confusing for anyone using
 *  this API. An API should be intuitive as well as useful, and I'm not sure if
 *  this additional type really helps with either goal.
 *  
 *  I already used a typedef to "erase" one level of indirection and I'm not
 *  sure another one would be well received, or even recommended.
 * 
 */

void CloseFile(File *fileHandle);

#endif // STD_C_FILE_H_
