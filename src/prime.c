// Nikita Kouevda
// 2014/12/20

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"

bool is_prime(const uint64_t num) {
  const uint64_t num_sqrt = sqrt(num);
  uint64_t i;

  if (num == 2 || num == 3) {
    return true;
  } else if (num < 2 || num % 2 == 0 || num % 3 == 0) {
    return false;
  }

  for (i = 5; i <= num_sqrt; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

uint64_t prime_range(const uint64_t start, const uint64_t stop,
                     const bool opt_short) {
  const uint64_t stop_sqrt = sqrt(stop);
  uint64_t *primes;
  // Smallest x divisible by 8 such that 8 * x >= stop
  uint64_t primes_size = (((stop - 1) | 63) + 1) >> 3;
  uint64_t count = 0;
  // NOTE: unlike num in is_prime, num is "zero-indexed" and refers to (num + 1)
  uint64_t num;
  uint64_t i;

  primes = malloc(primes_size);
  if (primes == NULL) {
    return UINT64_MAX;
  }
  memset(primes, UINT64_MAX, primes_size);

  for (num = 1; num < stop_sqrt; ++num) {
    if (*(primes + (num >> 6)) & (1ULL << (num % 64))) {
      if (num + 1 >= start) {
        ++count;
        if (!opt_short) {
          printf("%llu\n", num + 1);
        }
      }
      for (i = (num + 1) * (num + 1) - 1; i < stop; i += num + 1) {
        *(primes + (i >> 6)) &= ~(1ULL << (i % 64));
      }
    }
  }

  // Jump to start of range if necessary
  if (start > stop_sqrt + 1) {
    i = start - 1;
  }

  for ( ; num < stop - 1; ++num) {
    if (*(primes + (num >> 6)) & (1ULL << (num % 64))) {
      ++count;
      if (!opt_short) {
        printf("%llu\n", num + 1);
      }
    }
  }

  free(primes);
  primes = NULL;

  return count;
}
