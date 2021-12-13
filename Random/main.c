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
#include <stdint.h>
#include <errno.h>
#include <limits.h>
#include "xor.h"

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
    else if (argc >= 2 && !strcmp(argv[1], "gen"))
    {
        uint64_t min = 0, max = MAXULONGLONG;
        ULONG d_count = 1;

        // detect '--'
        for (int i = 2; i < argc; i++)
        {
            int opt_detector = strncmp(argv[i], "--", 2);
            if (opt_detector)
            {
                fprintf(stderr, "Invalid arguments\n\a");
                printf("Run 'rand --help' for usage.\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                char* endptr;
                errno = 0;
                if (i == argc - 1) // options without values;
                    goto error_no_values;

                if (strcmp(argv[i], "--max") == 0)
                {
                    max = strtoull(argv[++i], &endptr, 10);

                    if (errno == ERANGE)
                        goto error_range;
                    if (argv[i] == endptr)
                        goto error_no_values;
                    if (strchr(argv[i], '-'))
                        goto error_range;
                    continue;
                }
                
                if (strcmp(argv[i], "--min") == 0)
                {
                    min = strtoull(argv[++i], &endptr, 10);

                    if (errno == ERANGE)
                        goto error_range;
                    if (argv[i] == endptr)
                        goto error_no_values;
                    if (strchr(argv[i], '-'))
                        goto error_range;
                    continue;
                }
                
                if (strcmp(argv[i], "--count") == 0);
                {
                    d_count = strtoul(argv[++i], &endptr, 10);

                    if (errno == ERANGE)
                        goto error_range;
                    if (argv[i] == endptr) goto error_no_values;
                    continue;
                }
            }
        }
        if (min >= max) goto error_range;
        printf("\a");
        randXor64(min, max, d_count, unsorted);

    }
    else if (argc == 1)
    {
        return noArgExecution();
    }
    else
    {
        fprintf(stderr, "rand %s: Invalid command\n\a", argv[1]);
        printf("Run 'rand --help' for usage.\n");
        exit(EXIT_FAILURE);
    }

    return 0;


error_no_values:
    fprintf(stderr, "rand %s: No value with argument\n", argv[1]);
    exit(EXIT_FAILURE);

error_range:
    fprintf(stderr, "rand %s: Invalid range\n", argv[1]);
    exit(EXIT_FAILURE);
}