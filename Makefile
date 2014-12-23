# Nikita Kouevda
# 2014/12/22

# Compiler and options
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Werror -pedantic-errors -O2

# Sources and targets
SOURCES := $(wildcard src/*.c)
BIN_DIR := bin
BIN_NAME := prime

# Phony targets
.PHONY: all test clean

all: $(BIN_DIR)/$(BIN_NAME)

$(BIN_DIR)/$(BIN_NAME): $(SOURCES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

test: all
	test/run_tests

clean:
	rm -rf $(BIN_DIR)
