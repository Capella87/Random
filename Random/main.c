/*
 
================================================
┏━━━━━━━━┓
┃ Random ┃
┗━━━━━━━━┛
Developed by Capella87

Copyright (c) 2018-2021 Capella87

See cui.h to check version. It's moved there.
First commit date : Feb 24, 2018
Initial version release date : Feb 22, 2018

================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cui.h"
#include "core.h"

#ifdef _WIN32
#include <Windows.h>
#elif __linux__

#elif __APPLE__
#endif

int main(int argc, char** argv)
{
    if (argc == 2 && (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0))
    {
        showVersion();
        exit(EXIT_SUCCESS);
    }
    else if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        showHelp();
        exit(EXIT_SUCCESS);
    }
    else if (argc == 1)
    {
        return noArgExecution();
    }

    return 0;
}

