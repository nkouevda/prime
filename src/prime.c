// Nikita Kouevda
// 2014/02/21

#include <math.h>
#include <stdint.h>

#include "prime.h"

uint8_t is_prime(const uint64_t num) {
    if (num == 2 || num == 3) {
        return 1;
    } else if (num < 2 || num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

    const uint64_t max = sqrt(num);
    uint64_t i;

    for (i = 5; i <= max; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}
