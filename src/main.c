// Nikita Kouevda
// 2014/10/16

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"

int main(int argc, char *argv[]) {
  const char *usage = "usage: prime [-h|--help] [-v|--verbose] [--] number ...";
  bool verbose = false;
  bool end_opts = false;
  bool has_args = false;
  char *endptr;
  uint64_t num;
  int i;

  for (i = 1; i < argc; ++i) {
    if (!end_opts) {
      if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
        printf("%s\n", usage);
        return 0;
      } else if (
          strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
        verbose = true;
        continue;
      } else if (strcmp(argv[i], "--") == 0) {
        end_opts = true;
        continue;
      } else {
        end_opts = true;
        has_args = true;
      }
    }

    num = strtoull(argv[i], &endptr, 10);

    if (*endptr != '\0') {
      fprintf(stderr, "prime: illegal argument: %s\n", argv[i]);
      return 1;
    } else if (is_prime(num)) {
      printf(verbose ? "%s is prime\n" : "%s\n", argv[i]);
    } else if (verbose) {
      printf("%s is not prime\n", argv[i]);
    }
  }

  if (!has_args) {
    fprintf(stderr, "%s\n%s\n", "prime: missing arguments", usage);
    return 1;
  }

  return 0;
}
