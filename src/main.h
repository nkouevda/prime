// Nikita Kouevda
// 2014/12/18

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

int main(int argc, char *argv[]);

int check(int argc, char *argv[], const int optind, const bool opt_short);

int range(int argc, char *argv[], const int optind, const bool opt_short);

#endif
