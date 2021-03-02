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
#define VERSION         "1.1.1"
#define RELEASE_DATE    "Feb 17, 2021"

typedef int Digit;

void intro(void);
void showVersion(void);
void showHelp(void);
Digit alignment(int);

#endif