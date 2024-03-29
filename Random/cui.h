/****************************************************************************
 *    Copyright (c) 2021 Capella87                                          *
 *                                                                          *
 *   This file is part of Random program.                                   *
 *   github.com/Capella87/Random                                            *
 ****************************************************************************/

// Compromise functions and constants for the User interface in CLI mode.

#ifndef __CUI_H__
#define __CUI_H__
#include <stdbool.h>

#define WAIT_DEFAULT    0
#define YEAR            2021
#define VERSION         "v2.0.0-alpha-1"
#define RELEASE_DATE    "Oct 17, 2021"
#define COLCOUNT        10

typedef int Digit;
typedef unsigned long long uint64;
typedef enum _sortOptions { sorted, unsorted } SortOpt;

int noArgExecution(void);
void bufferFlush(void);
void intro(void);
void showVersion(void);
void showHelp(void);
Digit alignment(const uint64 maxNum);
void printInt64Result(uint64* result, const int count, const uint64 max);


#endif