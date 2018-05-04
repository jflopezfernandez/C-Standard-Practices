
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

#ifndef STDLIB_STDDEF_INCLUDED
#define STDLIB_STDDEF_INCLUDED
#include <stddef.h>
#endif // STDLIB_STDDEF_INCLUDED

#ifndef STDLIB_CTYPE_INCLUDED
#define  STDLIB_CTYPE_INCLUDED
#include <ctype.h>
#endif //  STDLIB_CTYPE_INCLUDED

#ifndef STDLIB_MATH_INCLUDED
#define STDLIB_MATH_INCLUDED
#include <math.h>
#endif // STDLIB_MATH_INCLUDED

#ifndef STDLIB_TIME_INCLUDED
#define STDLIB_TIME_INCLUDED
#include <time.h>
#endif // STDLIB_TIME_INCLUDED

#ifndef STDLIB_UCHAR_INCLUDED
#define STDLIB_UCHAR_INCLUDED
#include <uchar.h>
#endif // STDLIB_UCHAR_INCLUDED

// TODO: Create dedicated IO Module

#ifndef STD_C_FILE_H_
#include "file.h"
#endif // STD_C_FILE_H_

static File createHeaderFile(const char *headerFileName) {
    
    // TODO: Move this into its own function
    // Maybe getHeaderFileName(...) ? 
    char filename[32] = { 0 };

    strcpy(filename, headerFileName);
    strcat(filename, ".h");

    return createFile(filename);
}

static void CreateNewHeaderFile(const char *projectName, const char *headerFileName) {
    File header = createHeaderFile(headerFileName);

    fprintf(header, "\n");
    fprintf(header, "#ifndef %s_%s_H_\n", projectName, headerFileName);
    fprintf(header, "#define %s_%s_H_\n", projectName, headerFileName);
    fprintf(header, "\n\n");
    fprintf(header, "void TestFunction(void) {\n");
    fprintf(header, "\tprintf(\"testing...\\n\");\n");
    fprintf(header, "}\n");
    fprintf(header, "\n");
    fprintf(header, "#endif // %s_%s_H_\n", projectName, headerFileName);

    CloseFile(&header);
}


int main(void)
{
    const char *projectName = "TEST_PROJECT";

    const char *modules[] = {
        "IO",
        "File",
        "Math",
        "Error",
        "Time",
        "OS"
    };

    for (int i = 0; i < 6; i++) {
        CreateNewHeaderFile(projectName, modules[i]);
    }
    
    return EXIT_SUCCESS;
}