// Nikita Kouevda
// 2013/11/01

#include <iostream>

#include "prime.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: prime number ..." << endl;
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    cout << argv[i] << " is";

    if (!isPrime(atol(argv[i]))) {
      cout << " not";
    }

    cout << " prime" << endl;
  }

  return 0;
}
