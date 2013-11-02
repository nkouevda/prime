// Nikita Kouevda
// 2013/11/02

#include <cmath>

#include "prime.hpp"

using namespace std;

bool isPrime(long int n) {
  if (n == 2 || n == 3) {
    return true;
  } else if (n < 2 || n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  for (long int i = 5, max = sqrt(n) + 1; i < max; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}
