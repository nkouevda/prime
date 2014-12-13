// Nikita Kouevda
// 2014/12/13

#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <stdint.h>

bool is_prime(const uint64_t num);

uint64_t prime_range_count(const uint64_t min, const uint64_t max);

#endif
