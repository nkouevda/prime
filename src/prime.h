// Nikita Kouevda
// 2014/12/17

#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_prime(const uint64_t num);

uint64_t prime_range(FILE *stream, const uint64_t start, const uint64_t stop);

#endif
