// Nikita Kouevda
// 2014/12/18

#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <stdint.h>

bool is_prime(const uint64_t num);

uint64_t prime_range(const uint64_t start, const uint64_t stop,
                     const bool opt_short);

#endif
