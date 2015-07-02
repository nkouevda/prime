#ifndef PRIME_PRIME_H_
#define PRIME_PRIME_H_

#include <stdbool.h>
#include <stdint.h>

bool is_prime(const uint64_t num);

uint64_t prime_range(const uint64_t start, const uint64_t stop,
                     const bool opt_short);

#endif  // PRIME_PRIME_H_
