// Nikita Kouevda
// 2013/11/01

#include <cmath>

#include "prime.hpp"

using namespace std;

bool isPrime(long int n) {
  if (n == 2 || n == 3) {
    return 1;
  } else if (n < 2 || n % 2 == 0 || n % 3 == 0) {
    return 0;
  }

  for (long int i = 5; i < sqrt(n); i += 6) {
    if (n % i == 0 || (n + 2) % i == 0) {
      return 0;
    }
  }

  return 1;
}
