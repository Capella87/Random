#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "xor.h"

extern const uint64 XOR64_OFFSET;

// ref: https://en.wikipedia.org/wiki/Xorshift
void init_xor64(Xor64* t)
{
    t->seed = (uint64)time(0) ^ XOR64_OFFSET;
    get_xor64(t);
    t->seed ^= (uint64)time(0) << 13;
    get_xor64(t);
    t->seed ^= (uint64)time(0) << 7;
    get_xor64(t);
    t->seed ^= (uint64)time(0) << 17;
    if (!t->seed) t->seed = XOR64_OFFSET;
    return;
}

uint64 get_xor64(Xor64* t)
{
    uint64 target = t->seed;
    target ^= target >> 12;
    target ^= target << 25;
    target ^= target >> 27;
    t->seed = target;
    return target * 0x2545F4914F6CDD1DULL;
}

uint64 get_xor64_num(Xor64* t, uint64 min, uint64 max)
{
    // min == max == 0 -> no range option
    return (!min && !max) ? get_xor64(t) : (min + get_xor64(t) % (max - min));
}

bool rand_xor64(uint64 min, uint64 max, const int count, SortOpt op)
{
    Xor64 t;
    init_xor64(&t);

    t.result = (uint64*)malloc(sizeof(uint64) * count);
    t.count = count;
    for (int i = 0; i < count; i++)
        t.result[i] = get_xor64_num(&t, min, max);

    // Sort or skip process depending on 'op' argument;
    // It will use timsort.

    print_int64_result(t.result, t.count, max);

    free(t.result);
    return true;
}

void reset_xor64_seed(Xor64* t)
{
    t->seed = (uint64)time(0) ^ XOR64_OFFSET;
    get_xor64(t);
    t->seed ^= (uint64)time(0) << 13;
    get_xor64(t);
    t->seed ^= (uint64)time(0) << 17;
    get_xor64(t);
    t->seed ^= (uint64)time(0) << 5;
    if (!t->seed) t->seed = XOR64_OFFSET;
    return;
}