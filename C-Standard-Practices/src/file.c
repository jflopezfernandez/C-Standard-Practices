
#ifndef STD_C_FILE_H_
#include "file.h"
#endif //  STD_C_FILE_H_

static int FileHandleNull(File file) {
	if (!file) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

/** Function: static int FailedToOpenFile(File file)
 *  
 *  Is this a copy of "FileHandleNull(File file)"? I feel like having this
 *  specific function helps semantically understand the code, but I don't know
 *  how other developers would feel about having a function serving no other
 *  purpose aside from "wrapping" another function for understanding.
 * 
 */

static int FailedToOpenFile(File file) {
	if (FileHandleNull(file)) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static void ValidateFileHandle(File file) {
	if (FailedToOpenFile(file)) {
		perror("Failed to open file");

		exit(EXIT_FAILURE);
	}
}

File openFile(const char *filename, const char *mode) {
	File newFile(filename, mode);

	ValidateFileHandle(newFile);

	return newFile;
}

File createFile(const char *filename) {
	return openFile(filename, "w");
}

// TODO: Create a macro or function to validate all file pointer parameters

void CloseFile(File *fileHandle) {
	if (FileHandleNull(file)) {
		return;
	}

	if (fclose(*fileHandle) == EOF) {
		perror("Failed to close file");

		exit(EXIT_FAILURE);
	}

	*fileHandle == NULL;
}
