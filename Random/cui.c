#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cui.h"
#include "core.h"
#include "xor.h"

int interactive_mode(void)
{
    uint64 max, min;
    int count;
    char iterAnswer[51] = "";

    intro();
    while (1)
    {
        puts("Type number range: ");
        printf("Start > ");
        while (scanf("%llu", &min) != 1 || min < 0)
        {
            flush_buffer();
            printf("ERROR! Type only a natural number or zero!\n\a");
            printf("Start > ");
        }
        printf("Stop > ");
        while (scanf("%llu", &max) != 1 || max == 0)
        {
            flush_buffer();
            printf("ERROR! Type only a natural number!\n\a");
            printf("Stop > ");
        }

        puts("How many random numbers ?");
        printf("> ");
        while (scanf("%d", &count) != 1)
        {
            flush_buffer();
            printf("ERROR! Type correct number!\n\a");
            printf("> ");
        }
        flush_buffer();
        rand_xor64(min, max, count, unsorted);
        puts("Do you want to try again ?\a");
        printf("Type 'exit' to STOP program\n");
        printf(">> ");
        scanf("%[^\n]", iterAnswer);
        flush_buffer();
        if (!strcmp(iterAnswer, "exit")) break;
    }

    printf("Bye\n\a");
    return 0;
}

void intro(void)
{
    puts("Random - Generate random numbers quickly!");
    printf("Developed by Capella87.\n");
    printf("%s | %s\n", VERSION, RELEASE_DATE);
    printf("Copyright (c) 2018, 2021-2022 Capella87\n");
    puts("This software is distributed under MIT License. See LICENSE for more details.");
    puts("Repo: https://github.com/Capella87/Random");
    puts("---------------------------------------------\n");
}

void show_version(void)
{
    printf("Random %s (%s)\n", VERSION, RELEASE_DATE);
    puts("Repo: https://github.com/Capella87/Random");
}

void show_help(void)
{
    printf("Copyright (c) 2018, 2021-2022 Capella87\n");

    printf("usage: rand <command> [<options>]\n\n");
    puts("Commands");
    puts("    gen\t\tGenerate random numbers. You can use option for conditions");

    puts("\n\n\n");
}

Digit alignment(const uint64 max)
{
    return max ? (Digit)floor(log10((double)max) + 1) : 1;
}

// Flush all unneeded leftovers from buffer to prevent next input interference.
void flush_buffer(void)
{
    while (getchar() != '\n')
        continue;
}

void print_int64_result(uint64* result, const int count, const uint64 max)
{
    Digit digit = alignment((uint64)max);
    Digit iteration_digit = alignment((uint64)count);

    for (int i = 0; i < count; i++)
    {
        printf("%*llu ", digit, result[i]);
        if ((i + 1) % COLCOUNT == 0)
            printf("   | %0*d\n", iteration_digit, i + 1);
    }
    putchar('\n');
    return;
}