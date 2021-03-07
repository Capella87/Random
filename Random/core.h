/****************************************************************************
 *    Copyright (c) 2021 Capella87                                          *
 *                                                                          *
 *   This file is part of Random program.                                   *
 *   github.com/Capella87/Random                                            *
 ****************************************************************************/

 // Contains the most important features; calculating numbers..

#ifndef __CORE_H__
#define __CORE_H__
#include <stdbool.h>
#include <stdint.h>

int calcRand(int input, int iteration);
int countdown(int time);
void wait(int sec);
// uint32_t calcXor32(uint32_t[]);
uint64_t calcXor64(uint64_t*);
// uint32_t calcXor128(uint64_t[]);

#endif