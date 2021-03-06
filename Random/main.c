/*
 
================================================
┏━━━━━━━━┓
┃ Random ┃
┗━━━━━━━━┛
Developed by Capella87

Copyright (c) 2018-2021 Capella87

Random version : 1.2
Release date : Mar 4, 2021
First commit date : Feb 24, 2018
Initial version release date : Feb 22, 2018

================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "cui.h"
#include "core.h"

#define WINDOWS_X64

#ifdef WINDOWS_X64
#include <Windows.h>
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
	int max;
    int answer, num;

	intro();
    while (1)
    {
        puts("Type a maximum number: ");
        printf(">> ");
        while (scanf("%d", &max) != 1 || max == 0)
        {
            while (getchar() != '\n')
                continue;
            printf("ERROR! Type only a natural number!\n\a");
            printf(">> ");
        }

        puts("How many randomized numbers?: ");
        printf(">> ");
        while (scanf("%d", &num) != 1)
        {
            while (getchar() != '\n')
                continue;
            printf("ERROR! Type correct number!\n\a");
            printf(">> ");
        }
        countdown(WAIT_DEFAULT);
        calcRand(max, num); // It will be changed when other random algorithms are introduced.
        puts("Do you want to try again ?\a");
        printf("Type 0 to EXIT\n");
        printf(">> ");
        while (scanf("%d", &answer) != 1)
        {
            while (getchar() != '\n')
                continue;
            printf("ERROR! Please type a correct answer!\n");
            printf("> ");
        }
        if (answer == 0) break;
    }


    printf("Bye\n\a");
	return 0;
}

