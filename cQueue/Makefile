CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
SRCS = main.c node.c queue.c
TARGET = main

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
