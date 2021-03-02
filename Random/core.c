#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "core.h"
#include "cui.h"

// Using old school random algorithm embedded in C library
int calcRand(int input, int iteration)
{
    int output;
    Digit digit = alignment(input);
    Digit iterDigit = alignment(iteration);

    if (iteration == 0) return -1;
    srand((unsigned int)time(NULL));

    for (int i = 1; i <= iteration; i++)
    {
        output = rand() % input + 1;
        printf("%*d ", digit, output);
        if (i % 10 == 0)
            printf("   | %0*d\n", iterDigit, i);
    }
    putchar('\n');

    return 0;
}

void wait(int sec)
{
    clock_t endwait;
    endwait = clock() + sec * CLOCKS_PER_SEC;
    while (clock() < endwait);
}

int countdown(int time)
{
    if (time < 0) return -1;
    else if (time == 0) return 0;

    for (int n = time; n > 0; n--)
    {
        printf("Wait... ");
        printf("%d ", n);
        wait(time);
    }
    printf("0\n");

    return 0;
}
