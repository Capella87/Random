/*
 
================================================
┏━━━━━━━━┓
┃ Random ┃
┗━━━━━━━━┛
Developed by Capella87

Copyright (c) 2018-2021 Capella87

Random version : 1.1.1
Release date : Feb 17, 2021
First commit date : Feb 24, 2018
Initial version release date : Feb 22, 2018

================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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
    int ask, num;

	intro();
start:
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
	puts("Want to try again ?\a");
	printf("1 : Restart | 2 : EXIT\n");
	printf(">> ");
	scanf("%d", &ask);

	switch (ask)
	{
		case 1 :
			printf("Restart.\n");
			system("cls");
			goto start;
			break;
        default:
			break;
	}
    printf("Bye\n");

	return 0;
}

