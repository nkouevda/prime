// Nikita Kouevda
// 2014/03/06

#include <math.h>
#include <stdint.h>

#include "prime.h"

uint8_t is_prime(const uint64_t num) {
    const uint64_t max;
    uint64_t i;

    if (num == 2 || num == 3) {
        return 1;
    } else if (num < 2 || num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

    max = sqrt(num);

    for (i = 5; i <= max; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}
