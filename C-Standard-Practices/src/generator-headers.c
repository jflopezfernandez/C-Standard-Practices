
/** TODO: See if this is the most optimal way of including stdlib headers, as
 *  opposed to putting these includes in the corresponding header, or maybe
 *  just including "generator.h"
 * 
 */

#ifndef STDLIB_STDIO_INCLUDED
#define STDLIB_STDIO_INCLUDED
#include <stdio.h>
#endif // STDLIB_STDIO_INCLUDED

#ifndef STDLIB_STDLIB_INCLUDED
#define STDLIB_STDLIB_INCLUDED
#include <stdlib.h>
#endif // STDLIB_STDLIB_INCLUDED

#ifndef STDLIB_STRING_INCLUDED
#define STDLIB_STRING_INCLUDED
#include <string.h>
#endif // STDLIB_STRING_INCLUDED

#ifndef STD_C_FILE_H_
#include "file.h"
#endif // STD_C_FILE_H_

#ifndef STD_C_GENERATOR_HEADERS_H_
#include "generator/headers.h"
#endif // STD_C_GENERATOR_HEADERS_H_

// =============================================================================
// 
// 							HEADER FILE MACRO FUNCTIONS
//
// -----------------------------------------------------------------------------

static inline void PrintHeaderFileHeader(File header, const char *projectName, const char *headerFileName) {
    fprintf(header, "\n");
    fprintf(header, "#ifndef %s_%s_H_\n", projectName, headerFileName);
    fprintf(header, "#define %s_%s_H_\n", projectName, headerFileName);
    fprintf(header, "\n");
}

static inline void PrintHeaderFileFooter(File header, const char *projectName, const char *headerFileName) {
    fprintf(header, "\n");
    fprintf(header, "#endif // %s_%s_H_\n", projectName, headerFileName);
}

// -----------------------------------------------------------------------------

static inline void PrintFunctionDeclTypesAndName(File header, const char *specifier, const char *returnType, const char *name) {
    fprintf(header, "%s %s %s", specifier, returnType, name);
}

static inline void PrintFunctionArgs(File header, const char *arguments) {
    fprintf(header, "(%s)", arguments);
}

// =============================================================================
//
// 							FUNCTION MACRO FUNCTIONS
// 
// -----------------------------------------------------------------------------

static inline void PrintFunction(File header, const char *specifier, const char *returnType, const char *name, const char *arguments) {
    PrintFunctionDeclTypesAndName(header, specifier, returnType, name);
    PrintFunctionArgs(header, arguments);
}

static inline void PrintFunctionDeclaration(File header, const char *specifier, const char *returnType, const char *name, const char *arguments) {
    PrintFunction(header, specifier, returnType, name, arguments);
    
    fprintf(header, ";\\n\n");
}

static inline void PrintFunctionDefinition(File header, const char *specifier, const char *returnType, const char *name, const char *arguments, const char *body) {
    PrintFunction(header, specifier, returnType, name, arguments);

    fprintf(header, " {\n");
    fprintf(header, "%s", body);
    fprintf(header, "\n}\n");
}

/** Function: static inline void PrintTestFunctionDefinition(File header)
 *  
 *  This function is just a test function that will print out a simple printf
 *  function to the requested file. This is obviously not very useful but it is
 *  a good example of how to print out a function to a file by composing the
 *  given functions.
 * 
 */

static inline void PrintTestFunctionDefinition(File header) {
    PrintFunctionDefinition(header, "static inline", "void", "TestFunction", "void", "\tprintf(\"testing...\\n\");");
}

/** Function: File createHeaderFile(const char *headerFileName)
 *  
 *  This function does two things. First, it creates the name of the header file
 *  by appending a '.h' extension to the name of the header file. Second, it
 *  actually creates the file by calling the 'createFile' function defined in
 *  'file.h'.
 * 
 */

static File createHeaderFile(const char *headerFileName) {
    
    // TODO: Move this into its own function
    // Maybe getHeaderFileName(...) ? 
    char filename[32] = { 0 };

    strcpy(filename, headerFileName);
    strcat(filename, ".h");

    return createFile(filename);
}

/** Function: void CreateNewHeaderFile(const char *projectName, const char *headerFileName)
 *  
 *  This function calls "createHeaderFile" to create a file with a '.h' extension
 *  using the passed in header file name. Having done that, the function prints
 *  the header file header and footer.
 * 
 *  TODO: Need to come up with a way for the generator to print out as many
 *  functions as necessary. A possible way to do with might be using a linked
 *  list of pointers to a "function" struct that contains all the necessary
 *  arguments to pass to the PrintFunction functions, including whether the
 *  function in question is a declaration or a definition.
 * 
 */

void CreateNewHeaderFile(const char *projectName, const char *headerFileName) {
    File header = createHeaderFile(headerFileName);

    PrintHeaderFileHeader(header, projectName, headerFileName);
    
    // Header File Functions
    PrintTestFunctionDefinition(header);

    PrintHeaderFileFooter(header, projectName, headerFileName);

    CloseFile(&header);
}
