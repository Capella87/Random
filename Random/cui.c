#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cui.h"

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
    
    printf("usage: random [<command>] [<options>]\n");
}

Digit alignment(int max)
{
    return (Digit)floor(log10(max) + 1);
}