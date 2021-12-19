#ifndef XOR_H
#define XOR_H
#include <stdbool.h>
#include "cui.h"

static const uint64 XOR64_OFFSET = 13726359678912485784UL;

// ref: https://github.com/Bunny83/Utilities/blob/master/XorShift64.cs
// Original Code Author: Markus Göbel (Bunny83)
// I ported part of his code to C.

typedef struct _xor64
{
    uint64 seed;
    uint64* result;
    int count;
} Xor64;

void init_xor64(Xor64* t);
uint64 get_xor64(Xor64* t);
uint64 get_xor64_num(Xor64* t, uint64 min, uint64 max);
bool rand_xor64(uint64 min, uint64 max, const int count, SortOpt op);
void reset_xor64_seed(Xor64* t);

#endif