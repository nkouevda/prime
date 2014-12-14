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
    {"stat", no_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}
};

void usage(FILE *stream, const char *prog) {
  fprintf(stream, "usage: %s [-h|--help]\n", prog);
  fprintf(stream, "       %s [-s|--stat] [--] num ...\n", prog);
  fprintf(stream, "       %s [-s|--stat] [-r|--range] min max\n", prog);
}

int main(int argc, char *argv[]) {
  int opt;
  bool opt_stat = false;
  bool opt_range = false;

  while ((opt = getopt_long(argc, argv, "hrs", long_options, NULL)) != -1) {
    switch (opt) {
      case 'h':
        usage(stdout, argv[0]);
        return 0;
      case 'r':
        opt_range = true;
        break;
      case 's':
        opt_stat = true;
        break;
      case '?':
        usage(stderr, argv[0]);
        return 1;
    }
  }

  return (opt_range ? range : check)(argc, argv, optind, opt_stat);
}

int check(int argc, char *argv[], const int optind, const bool opt_stat) {
  int i;
  char *endptr;
  uint64_t num;
  uint64_t total = 0;
  uint64_t count = 0;

  if (optind >= argc) {
    fprintf(stderr, "%s: missing arguments\n", argv[0]);
    usage(stderr, argv[0]);
    return 1;
  }

  for (i = optind; i < argc; ++i) {
    num = strtoull(argv[i], &endptr, 10);
    ++total;
    if (*endptr != '\0') {
      fprintf(stderr, "%s: illegal argument: %s\n", argv[0], argv[i]);
      usage(stderr, argv[0]);
      return 1;
    }

    if (is_prime(num)) {
      ++count;
      if (!opt_stat) {
        printf("%s\n", argv[i]);
      }
    }
  }

  if (opt_stat) {
    printf("%llu of %llu (%f%%)\n", count, total, 1.0 * count / total);
  }
  return 0;
}

int range(int argc, char *argv[], const int optind, const bool opt_stat) {
  char *endptr;
  uint64_t min;
  uint64_t max;
  uint64_t total;
  uint64_t count;

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

  count = prime_range(opt_stat ? NULL : stdout, min, max);
  if (count == U64_MAX) {
    fprintf(stderr, "%s: unexpected error\n", argv[0]);
    return 1;
  }
  if (opt_stat) {
    total = max - min;
    printf("%llu of %llu (%f%%) in [%s, %s)\n",
           count, total, 1.0 * count / total, argv[optind], argv[optind + 1]);
  }
  return 0;
}
