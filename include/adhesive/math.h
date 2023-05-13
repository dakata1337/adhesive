#ifndef _ADHESIVE_MATH_
#define _ADHESIVE_MATH_

#include <stdint.h>

static inline uint64_t u64_next_pow(uint64_t n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    n++;
    return n;
}

static inline uint32_t u32_next_pow(uint32_t n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

#endif // _ADHESIVE_MATH_
