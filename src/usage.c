// Nikita Kouevda
// 2014/12/21

#include <stdio.h>

void usage(FILE *stream, const char *prog) {
  fprintf(stream, "usage: %s [-h|--help]\n", prog);
  fprintf(stream, "       %s [-s|--short] [--] <num>...\n", prog);
  fprintf(stream, "       %s [-s|--short] -r|--range [<start>] <stop>\n", prog);
}

void help(const char *prog) {
  printf("%s - Prime checker and finder\n\n", prog);
  usage(stdout, prog);
  fputs("\
\n\
prime [-h|--help]\n\
\n\
    Show this help message and exit.\n\
\n\
prime [-s|--short] [--] <num>...\n\
\n\
    Print each prime number of the given <num>s. If --short is specified,\n\
    instead of printing each prime number, output a summary in the following\n\
    format, where P is the number of primes and T is the number of <num>s:\n\
\n\
        P of T (P/T%%)\n\
\n\
prime [-s|--short] -r|--range [<start>] <stop>\n\
\n\
    Print all primes between <start> (inclusive) and <stop> (exclusive). If not\n\
    specified, <start> defaults to 0. If --short is specified, instead of\n\
    printing each prime number, output a summary in the following format, where\n\
    P is the number of primes and T is the number of numbers (<stop> - <start>):\n\
\n\
        P of T (P/T%%) in [<start>, <stop>)\n\
", stdout);
}
