CC:=gcc
CFLAGS:=-Wall -Wextra

SRC_DIRS:=$(wildcard src/*/)
SRCS:=$(foreach dir,$(SRC_DIRS),$(wildcard $(dir)*.c))
OBJS:=$(SRCS:.c=.o)

.PHONY: all clean

all: run

run: compile
	./main

compile: $(OBJS)
	$(CC) $(CFLAGS) $^ -o main

clean:
	rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
