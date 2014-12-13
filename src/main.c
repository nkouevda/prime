// Nikita Kouevda
// 2014/12/13

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"

void usage(FILE *stream, const char *prog) {
  fprintf(stream, "usage: %s [-h|--help]\n", prog);
  fprintf(stream, "       %s [-v|--verbose] [--] num ...\n", prog);
  fprintf(stream, "       %s [-v|--verbose] [-r|--range] min max\n", prog);
}

int main(int argc, char *argv[]) {
  bool verbose = false;
  bool end_opts = false;
  bool has_args = false;
  char *endptr;
  uint64_t num;
  uint64_t min;
  uint64_t max;
  int i;

  for (i = 1; i < argc; ++i) {
    if (!end_opts) {
      if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
        usage(stdout, argv[0]);
        return 0;
      } else if (
          strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--range") == 0) {
        if (i + 2 >= argc) {
          fprintf(stderr, "prime: insufficient arguments\n");
          usage(stderr, argv[0]);
          return 1;
        }

        min = strtoull(argv[i + 1], &endptr, 10);
        if (*endptr != '\0') {
          fprintf(stderr, "prime: illegal argument: %s\n", argv[i + 1]);
          usage(stderr, argv[0]);
          return 1;
        }

        max = strtoull(argv[i + 2], &endptr, 10);
        if (*endptr != '\0') {
          fprintf(stderr, "prime: illegal argument: %s\n", argv[i + 2]);
          usage(stderr, argv[0]);
          return 1;
        }

        if (verbose) {
          printf("primes between %s and %s: ", argv[i + 1], argv[i + 2]);
        }
        printf("%llu\n", prime_range_count(min, max));
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
      usage(stderr, argv[0]);
      return 1;
    }

    if (is_prime(num)) {
      printf(verbose ? "%s is prime\n" : "%s\n", argv[i]);
    } else if (verbose) {
      printf("%s is not prime\n", argv[i]);
    }
  }

  if (!has_args) {
    fprintf(stderr, "%s: missing arguments\n", argv[0]);
    usage(stderr, argv[0]);
    return 1;
  }

  return 0;
}
