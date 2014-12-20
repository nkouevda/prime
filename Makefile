# Nikita Kouevda
# 2014/12/19

# Compiler and options
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Werror -pedantic-errors -O2

# Sources and targets
SOURCES := $(wildcard src/*.c)
TARGET := bin/prime

# Phony targets
.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

test: all
	test/run_tests

clean:
	rm -f $(TARGET)
