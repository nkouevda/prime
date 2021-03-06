#ifndef PRIME_MAIN_H_
#define PRIME_MAIN_H_

#include <getopt.h>
#include <stdbool.h>

static const struct option long_options[];

int main(int argc, char *argv[]);

int check(int argc, char *argv[], const bool opt_short);

int range(int argc, char *argv[], const bool opt_short);

#endif  // PRIME_MAIN_H_
