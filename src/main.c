// Nikita Kouevda
// 2014/02/18

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"

int main(int argc, char *argv[]) {
  const char *usage = "usage: prime [-h] number ...";

  if (argc < 2) {
    fprintf(stderr, "%s\n", usage);

    return 1;
  } else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
    printf("%s\n", usage);

    return 0;
  }

  char *endptr;
  int i;
  uint64_t num;

  for (i = 1; i < argc; ++i) {
    num = strtoull(argv[i], &endptr, 10);

    if (*endptr) {
      fprintf(stderr, "prime: illegal argument: %s\n", argv[i]);
    } else if (is_prime(num)) {
      printf("%s is prime\n", argv[i]);
    } else {
      printf("%s is not prime\n", argv[i]);
    }
  }

  return 0;
}
