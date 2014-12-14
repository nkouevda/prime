// Nikita Kouevda
// 2014/12/13

#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define UINT64_MSB 0x8000000000000000ULL

bool is_prime(const uint64_t num);

uint64_t prime_range(FILE *stream, const uint64_t min, const uint64_t max);

#endif
