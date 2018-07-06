#ifndef PRIME_USAGE_H_
#define PRIME_USAGE_H_

#include <stdio.h>

#define PROGRAM_NAME "prime"

void usage(FILE *stream);

void error(const char *format, ...);

void help(void);

#endif  // PRIME_USAGE_H_
