#include <stdarg.h>
#include <stdio.h>

#include "usage.h"

void usage(FILE *stream) {
  fputs("\
usage: " PROGRAM_NAME " [-h|--help]\n\
       " PROGRAM_NAME " [-s|--short] [--] <num>...\n\
       " PROGRAM_NAME " [-s|--short] -r|--range [<start>] <stop>\n\
", stream);
}

void error(const char *format, ...) {
  va_list args;

  fputs(PROGRAM_NAME ": ", stderr);
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  usage(stderr);
}

void help(void) {
  fputs(PROGRAM_NAME " - Prime checker and finder\n\n", stdout);
  usage(stdout);
  fputs("\
\n\
" PROGRAM_NAME " [-h|--help]\n\
\n\
    Show this help message and exit.\n\
\n\
" PROGRAM_NAME " [-s|--short] [--] <num>...\n\
\n\
    Print each prime number of the given <num>s. If --short is specified,\n\
    instead of printing each prime number, output a summary in the following\n\
    format, where P is the number of primes and T is the number of <num>s:\n\
\n\
        P of T (P/T%%)\n\
\n\
" PROGRAM_NAME " [-s|--short] -r|--range [<start>] <stop>\n\
\n\
    Print all primes between <start> (inclusive) and <stop> (exclusive). If not\n\
    specified, <start> defaults to 0. If --short is specified, instead of\n\
    printing each prime number, output a summary in the following format, where\n\
    P is the number of primes and T is the number of numbers (<stop> - <start>):\n\
\n\
        P of T (P/T%%) in [<start>, <stop>)\n\
", stdout);
}
