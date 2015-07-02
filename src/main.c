#include <errno.h>
#include <getopt.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "prime.h"
#include "usage.h"

static const struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"range", no_argument, NULL, 'r'},
    {"short", no_argument, NULL, 's'},
    {NULL, 0, NULL, 0}
};

int main(int argc, char *argv[]) {
  int opt;
  bool opt_range = false;
  bool opt_short = false;

  while ((opt = getopt_long(argc, argv, "hrs", long_options, NULL)) != -1) {
    switch (opt) {
      case 'h':
        help();
        return 0;
      case 'r':
        opt_range = true;
        break;
      case 's':
        opt_short = true;
        break;
      default:
        usage(stderr);
        return 1;
    }
  }

  if (optind >= argc) {
    error("missing arguments\n");
    return 1;
  }

  return (opt_range ? range : check)(argc, argv, optind, opt_short);
}

int check(int argc, char *argv[], const int optind, const bool opt_short) {
  int i;
  char *endptr;
  uint64_t num;
  uint64_t total;
  uint64_t count = 0;

  for (i = optind; i < argc; ++i) {
    num = strtoull(argv[i], &endptr, 10);
    if (*endptr != '\0') {
      error("illegal argument: %s\n", argv[i]);
      return 1;
    } else if (errno == ERANGE) {
      error("out of range: %s\n", argv[i]);
      return 1;
    }

    if (is_prime(num)) {
      ++count;
      if (!opt_short) {
        printf("%" PRIu64 "\n", num);
      }
    }
  }

  if (opt_short) {
    total = argc - optind;
    printf("%" PRIu64 " of %" PRIu64 " (%f%%)\n",
           count, total, 100.0 * count / total);
  }
  return 0;
}

int range(int argc, char *argv[], const int optind, const bool opt_short) {
  char *endptr;
  uint64_t start;
  uint64_t stop;
  uint64_t total;
  uint64_t count;

  if (optind + 2 < argc) {
    error("too many arguments\n");
    return 1;
  }

  start = strtoull(argv[optind], &endptr, 10);
  if (*endptr != '\0') {
    error("illegal argument: %s\n", argv[optind]);
    return 1;
  } else if (errno == ERANGE) {
    error("out of range: %s\n", argv[optind]);
    return 1;
  }

  if (optind + 1 == argc) {
    stop = start;
    start = 0;
  } else {
    stop = strtoull(argv[optind + 1], &endptr, 10);
    if (*endptr != '\0') {
      error("illegal argument: %s\n", argv[optind + 1]);
      return 1;
    } else if (errno == ERANGE) {
      error("out of range: %s\n", argv[optind + 1]);
      return 1;
    } else if (start > stop) {
      error("start must be <= stop\n");
      return 1;
    }
  }

  count = prime_range(start, stop, opt_short);
  if (count == UINT64_MAX) {
    error("unexpected error\n");
    return 1;
  }

  if (opt_short) {
    total = stop - start;
    printf("%" PRIu64 " of %" PRIu64 " (%f%%) in [%" PRIu64 ", %" PRIu64 ")\n",
           count, total, 100.0 * count / total, start, stop);
  }
  return 0;
}
