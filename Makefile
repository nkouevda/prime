CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Werror -pedantic-errors -O2

srcdir := src
sources := $(wildcard $(srcdir)/*.c)
bindir := bin
prime := $(bindir)/prime

.PHONY: all test clean

all: $(prime)

$(prime): $(sources)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -o $@ $(sources)

test: all
	test/run_tests

clean:
	rm -rf $(bindir)
