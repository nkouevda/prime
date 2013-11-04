// Nikita Kouevda
// 2013/11/04

#include <cstdlib>
#include <iostream>

#include "prime.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  int i, n;
  char *endptr;

  if (argc < 2) {
    cerr << "usage: prime number ..." << endl;
    return 1;
  }

  for (i = 1; i < argc; ++i) {
    n = strtol(argv[i], &endptr, 10);

    if (*endptr) {
      cerr << "prime: illegal argument: " << argv[i] << endl;
      continue;
    }

    cout << argv[i] << " is";

    if (!isPrime(n)) {
      cout << " not";
    }

    cout << " prime" << endl;
  }

  return 0;
}
