// Nikita Kouevda
// 2014/12/13

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>

void usage(FILE *stream, const char *prog);

int main(int argc, char *argv[]);

int check(int argc, char *argv[], const int optind, const bool stat);

int range(int argc, char *argv[], const int optind, const bool stat);

#endif
