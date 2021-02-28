#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "cui.h"

void intro(void)
{
    puts("Random - Select numbers in randomized ways");
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
}

void showHelp(void)
{
    printf("Random version %s (%s)\n", VERSION, RELEASE_DATE);
    printf("Copyright (c) 2018-%d Capella87.\n", YEAR);
    printf("https://github.com/Capella87/Random\n\n");
    
    printf("usage: random [<command>] [<options>]\n");
}