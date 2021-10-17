#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "xor.h"

extern const uint64 XOR64_OFFSET;

void initXor64(Xor64* t)
{
    t->seed = (uint64)time(0) ^ XOR64_OFFSET;
    getXor64(t);
    t->seed ^= (uint64)time(0) << 13;
    getXor64(t);
    t->seed ^= (uint64)time(0) << 17;
    getXor64(t);
    t->seed ^= (uint64)time(0) << 5;
    if (!t->seed) t->seed = XOR64_OFFSET;
    return;
}

uint64 getXor64(Xor64* t)
{
    uint64 target = t->seed;
    target ^= target >> 12;
    target ^= target << 25;
    target ^= target >> 27;
    t->seed = target;
    return target * 0x2545F4914F6CDD1DULL;
}

uint64 getXor64Num(Xor64* t, uint64 min, uint64 max)
{
    // min == max == 0 -> no range option
    return (!min && !max) ? getXor64(t) : (min + getXor64(t) % (max - min));
}

bool randXor64(uint64 min, uint64 max, const int count, SortOpt op)
{
    Xor64 t;
    initXor64(&t);

    t.result = (uint64*)malloc(sizeof(uint64) * count);
    t.count = count;
    for (int i = 0; i < count; i++)
    {
        t.result[i] = getXor64Num(&t, min, max);
    }

    printInt64Result(t.result, t.count, max);
    free(t.result);
    return true;
}