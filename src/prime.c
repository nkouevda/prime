// Nikita Kouevda
// 2014/12/17

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"

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

uint64_t prime_range(FILE *stream, const uint64_t start, const uint64_t stop) {
  uint64_t *primes;
  // Smallest x divisible by 8 such that 8 * x >= stop
  uint64_t primes_size = (((stop - 1) | 63) + 1) >> 3;
  uint64_t stop_sqrt = sqrt(stop);
  uint64_t count = 0;
  uint64_t i;
  uint64_t j;

  primes = malloc(primes_size);
  if (primes == NULL) {
    return UINT64_MAX;
  }
  memset(primes, UINT64_MAX, primes_size);

  for (i = 1; i < stop_sqrt; ++i) {
    if (*(primes + (i >> 6)) & (1ULL << (i % 64))) {
      if (i + 1 >= start) {
        ++count;
        if (stream != NULL) {
          fprintf(stream, "%llu\n", i + 1);
        }
      }
      // i * (i + 2) == (i + 1) * (i + 1) - 1
      for (j = i * (i + 2); j < stop; j += i + 1) {
        *(primes + (j >> 6)) &= ~(1ULL << (j % 64));
      }
    }
  }

  for (i = (start > stop_sqrt + 1) ? start - 1 : stop_sqrt; i < stop - 1; ++i) {
    if (*(primes + (i >> 6)) & (1ULL << (i % 64))) {
      ++count;
      if (stream != NULL) {
        fprintf(stream, "%llu\n", i + 1);
      }
    }
  }

  free(primes);
  primes = NULL;

  return count;
}
