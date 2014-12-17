// Nikita Kouevda
// 2014/12/16

#include <stdio.h>

void usage(FILE *stream, const char *prog) {
  fprintf(stream, "usage: %s [-h|--help]\n", prog);
  fprintf(stream, "       %s [-s|--stat] [--] <num>...\n", prog);
  fprintf(stream, "       %s [-s|--stat] -r|--range [<start>] <stop>\n", prog);
}

void help(FILE *stream, const char *prog) {
  fprintf(stream, "%s - Prime checker and finder\n\n", prog);
  usage(stream, prog);
  fprintf(stream,
"\n"
"prime [-h|--help]\n"
"\n"
"    Show this help message and exit.\n"
"\n"
"prime [-s|--stat] [--] <num>...\n"
"\n"
"    Print each prime number of the given numbers. If --stat is specified,\n"
"    instead of printing each prime number, output stats in the following format,\n"
"    where P is the number of primes and T is the number of numbers:\n"
"\n"
"        P of T (P/T%%)\n"
"\n"
"prime [-s|--stat] -r|--range [<start>] <stop>\n"
"\n"
"    Print all primes between <start> (inclusive) and <stop> (exclusive). If not\n"
"    specified, <start> defaults to 0. If --stat is specified, instead of\n"
"    printing all prime numbers in the given range, output stats in the following\n"
"    format, where P is the number of primes and T is the number of numbers:\n"
"\n"
"        P of T (P/T%%) in [<start>, <stop>)\n"
  );
}
