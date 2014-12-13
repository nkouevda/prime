// Nikita Kouevda
// 2014/12/13

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"

#define U64_MAX 0xffffffffffffffffULL
#define U64_MSB 0x8000000000000000ULL

bool is_prime(const uint64_t num) {
  uint64_t num_sqrt;
  uint64_t i;

  if (num == 2 || num == 3) {
    return true;
  } else if (num < 2 || num % 2 == 0 || num % 3 == 0) {
    return false;
  }

  num_sqrt = sqrt(num);

  for (i = 5; i <= num_sqrt; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

uint64_t prime_range_count(const uint64_t min, const uint64_t max) {
  uint64_t *primes;
  // Smallest x divisible by 8 such that 8 * x >= max
  uint64_t primes_size = (((max - 1) | 63) + 1) >> 3;
  uint64_t max_sqrt = sqrt(max);
  uint64_t count = 0;
  uint64_t i;
  uint64_t j;

  primes = malloc(primes_size);
  if (primes == NULL) {
    return 0;
  }
  memset(primes, U64_MAX, primes_size);

  for (i = 1; i < max_sqrt; ++i) {
    if (*(primes + (i >> 6)) & (U64_MSB >> (i % 64))) {
      if (i + 1 >= min) {
        ++count;
      }
      // i * (i + 2) == (i + 1) * (i + 1) - 1
      for (j = i * (i + 2); j < max; j += i + 1) {
        *(primes + (j >> 6)) &= ~(U64_MSB >> (j % 64));
      }
    }
  }

  for (i = (min > max_sqrt + 1) ? min - 1 : max_sqrt; i < max - 1; ++i) {
    if (*(primes + (i >> 6)) & (U64_MSB >> (i % 64))) {
      ++count;
    }
  }

  free(primes);
  primes = NULL;

  return count;
}
