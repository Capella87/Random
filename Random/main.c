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

#define WINDOWS_X64

#ifdef WINDOWS_X64
#include <Windows.h>
#endif

int calc(int);
void wait(int);

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
	int input_no;
	int result;
	int ask;

	intro();
start:
	puts("Type a maximum number: ");
    printf(">> ");
    while (scanf("%d", &input_no) != 1 || input_no == 0)
    {
        while (getchar() != '\n')
            continue;
        printf("ERROR! Type only a natural number!\n");
        printf(">> ");
    }

	result = calc(input_no);
	printf("Result : %d between 0 to %d\n\a\n", result, input_no);
	puts("Want to try again ?");
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

int calc(int input)
{
	for (int n = WAIT_DEFAULT; n > 0; n--)
	{
        printf("Wait... ");
		printf("%d ", n);
		wait(1);
	}
	printf("0\n");
	srand((unsigned int)time(NULL));
	int output = rand() % input + 1;

	return output;
}

void wait(int sec)
{
	clock_t endwait;
	endwait = clock() + sec * CLOCKS_PER_SEC;
	while (clock() < endwait);
}
