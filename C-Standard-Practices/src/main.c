
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

#ifndef STD_C_GENERATOR_H_
#include "generator.h"
#endif // STD_C_GENERATOR_H_


int main(void)
{
    const char *projectName = "OpenGL_Subsystem";

    const char *modules[] = {
        "IO",
        "File",
        "Math",
        "Error",
        "Time",
        "OS",
        "Renderer",
        "OpenGL"
    };

    for (int i = 0; i < 6; i++) {
        CreateNewHeaderFile(projectName, modules[i]);
    }

    return EXIT_SUCCESS;
}