# Nikita Kouevda
# 2013/11/01

# Compiler and options
CC := g++
CFLAGS := -Wall -O2

# Sources and targets
SOURCES := $(wildcard src/*.cpp)
TARGET := bin/prime

# Phony targets
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -r $(TARGET)
