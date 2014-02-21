# Nikita Kouevda
# 2014/02/20

# Compiler and options
CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic-errors -O2

# Sources and targets
SOURCES := $(wildcard src/*.c)
TARGET := bin/prime

# Phony targets
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
