#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cui.h"
#include "core.h"
#include "xor.h"

int noArgExecution(void)
{
    uint64 max, min;
    int count;
    char iterAnswer[51] = "";

    intro();
    while (1)
    {
        puts("Type number range: ");
        printf("From >> ");
        while (scanf("%llu", &min) != 1 || min < 0)
        {
            bufferFlush();
            printf("ERROR! Type only a natural number or zero!\n\a");
            printf("From >> ");
        }
        printf("To >> ");
        while (scanf("%llu", &max) != 1 || max == 0)
        {
            bufferFlush();
            printf("ERROR! Type only a natural number!\n\a");
            printf("To >> ");
        }

        puts("How many randomized numbers?: ");
        printf(">> ");
        while (scanf("%d", &count) != 1)
        {
            bufferFlush();
            printf("ERROR! Type correct number!\n\a");
            printf(">> ");
        }
        bufferFlush();
        randXor64(min, max, count, unsorted);
        puts("Do you want to try again ?\a");
        printf("Type exit to STOP program\n");
        printf(">> ");
        scanf("%[^\n]", iterAnswer);
        bufferFlush();
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

Digit alignment(const uint64 max)
{
    return max ? (Digit)floor(log10((double)max) + 1) : 1;
}

// Flush all unneeded leftovers from buffer to prevent next input interference.
void bufferFlush(void)
{
    while (getchar() != '\n')
        continue;
}

void printInt64Result(uint64* result, const int count, const uint64 max)
{
    Digit digit = alignment((uint64)max);
    Digit iterDigit = alignment((uint64)count);

    for (int i = 0; i < count; i++)
    {
        printf("%*llu ", digit, result[i]);
        if ((i + 1) % COLCOUNT == 0)
            printf("   | %0*d\n", iterDigit, i + 1);
    }
    putchar('\n');
    return;
}