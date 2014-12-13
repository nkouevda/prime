// Nikita Kouevda
// 2014/12/13

#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "prime.h"

static struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"range", no_argument, NULL, 'r'},
    {"verbose", no_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}
};

void usage(FILE *stream, const char *prog) {
  fprintf(stream, "usage: %s [-h|--help]\n", prog);
  fprintf(stream, "       %s [-v|--verbose] [--] num ...\n", prog);
  fprintf(stream, "       %s [-v|--verbose] [-r|--range] min max\n", prog);
}

int main(int argc, char *argv[]) {
  int opt;
  int i;
  bool verbose = false;
  char *endptr;
  uint64_t num;

  while ((opt = getopt_long(argc, argv, "hrv", long_options, NULL)) != -1) {
    switch (opt) {
      case 'h':
        usage(stdout, argv[0]);
        return 0;
      case 'r':
        return range(argc, argv, optind, verbose);
      case 'v':
        verbose = true;
        break;
      case '?':
        usage(stderr, argv[0]);
        return 1;
    }
  }

  if (optind >= argc) {
    fprintf(stderr, "%s: missing arguments\n", argv[0]);
    usage(stderr, argv[0]);
    return 1;
  }

  for (i = optind; i < argc; ++i) {
    num = strtoull(argv[i], &endptr, 10);
    if (*endptr != '\0') {
      fprintf(stderr, "%s: illegal argument: %s\n", argv[0], argv[i]);
      usage(stderr, argv[0]);
      return 1;
    }

    if (is_prime(num)) {
      printf(verbose ? "%s is prime\n" : "%s\n", argv[i]);
    } else if (verbose) {
      printf("%s is not prime\n", argv[i]);
    }
  }

  return 0;
}

int range(int argc, char *argv[], int optind, bool verbose) {
  char *endptr;
  uint64_t min;
  uint64_t max;

  if (optind + 1 >= argc) {
    fprintf(stderr, "%s: insufficient arguments\n", argv[0]);
    usage(stderr, argv[0]);
    return 1;
  } else if (optind + 2 < argc) {
    fprintf(stderr, "%s: too many arguments\n", argv[0]);
    usage(stderr, argv[0]);
    return 1;
  }

  min = strtoull(argv[optind], &endptr, 10);
  if (*endptr != '\0') {
    fprintf(stderr, "%s: illegal argument: %s\n", argv[0], argv[optind]);
    usage(stderr, argv[0]);
    return 1;
  }

  max = strtoull(argv[optind + 1], &endptr, 10);
  if (*endptr != '\0') {
    fprintf(stderr, "%s: illegal argument: %s\n", argv[0], argv[optind + 1]);
    usage(stderr, argv[0]);
    return 1;
  }

  if (verbose) {
    printf("primes in [%s, %s): ", argv[optind], argv[optind + 1]);
  }
  printf("%llu\n", prime_range_count(min, max));
  return 0;
}
