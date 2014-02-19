# Nikita Kouevda
# 2014/02/18

# Compiler and options
CC := gcc
CFLAGS := -Wall -O2

# Sources and targets
SOURCES := $(wildcard src/*.c)
TARGET := bin/prime

# Phony targets
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm $(TARGET)
