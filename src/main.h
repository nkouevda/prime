// Nikita Kouevda
// 2014/12/13

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>

void usage(FILE *stream, const char *prog);

int main(int argc, char *argv[]);

int range(int argc, char *argv[], int optind, bool verbose);

#endif
