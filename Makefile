CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Werror -O2

srcdir := src
sources := $(wildcard $(srcdir)/*.c)
bindir := bin
prime := $(bindir)/prime
destdir := $(HOME)/$(bindir)

.PHONY: all test install clean

all: $(prime)

$(prime): $(sources)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -o $@ $(sources)

test: all
	test/run_tests

install: all
	mkdir -p $(destdir)
	cp $(prime) $(destdir)

clean:
	rm -rf $(bindir)
