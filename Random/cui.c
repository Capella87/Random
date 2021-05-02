#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cui.h"
#include "core.h"

int noArgExecution(void)
{
    int max, min;
    int num;
    char iterAnswer[51] = "";

    intro();
    while (1)
    {
        puts("Type number range: ");
        printf("From >> ");
        while (scanf("%d", &min) != 1 || min < 0)
        {
            while (getchar() != '\n')
                continue;
            printf("ERROR! Type only a natural number or zero!\n\a");
            printf("From >> ");
        }
        printf("To >> ");
        while (scanf("%d", &max) != 1 || max == 0)
        {
            while (getchar() != '\n')
                continue;
            printf("ERROR! Type only a natural number!\n\a");
            printf("To >> ");
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
        while (getchar() != '\n')
            continue;
        calcRand(min, max, num); // It will be changed when other random algorithms are introduced.
        puts("Do you want to try again ?\a");
        printf("Type exit to STOP program\n");
        printf(">> ");
        scanf("%[^\n]", iterAnswer);
        while (getchar() != '\n')
            continue;
        if (!strcmp(iterAnswer, "exit")) break;
    }

    printf("Bye\n\a");
    return 0;
}

void intro(void)
{
    puts("Random - Generate randomized numbers quickly!");
    printf("Developed by Capella87.\n");
    printf("%s | %s\n", VERSION, RELEASE_DATE);
    printf("Copyright (c) 2018-%d Capella87\n", YEAR);
    puts("This software is distributed under MIT License. See LICENCE at the root directory for more details.");
    puts("https://github.com/Capella87/Random");
    puts("---------------------------------------------\n");
}

void showVersion(void)
{
    printf("Random version %s (%s)\n", VERSION, RELEASE_DATE);
    puts("https://github.com/Capella87/Random");
}

void showHelp(void)
{
    printf("Random version %s (%s)\n", VERSION, RELEASE_DATE);
    printf("Copyright (c) 2018-%d Capella87.\n", YEAR);
    printf("https://github.com/Capella87/Random \n\n");
    
    printf("usage: random <command> [<options>]\n\n");
    puts("Commands");
    puts("    generate\t\tGenerate random numbers. You can use option for conditions");
    puts("    config\t\tAdjust configurations");

    puts("\n\n\n");
}

Digit alignment(int max)
{
    return (Digit)floor(log10(max) + 1);
}