// Nikita Kouevda
// 2014/10/15

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#include "prime.h"

bool is_prime(const uint64_t num) {
  uint64_t max;
  uint64_t i;

  if (num == 2 || num == 3) {
    return true;
  } else if (num < 2 || num % 2 == 0 || num % 3 == 0) {
    return false;
  }

  max = sqrt(num);

  for (i = 5; i <= max; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}
