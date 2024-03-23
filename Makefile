CC:=gcc
CFLAGS:=-Wall -Wextra -Wpedantic -O3
LD:=gcc
LDFLAGS:=-lSDL2 -lSDL2_image

SRC_DIRS:=$(wildcard src/*/)
SRCS:=$(foreach dir,$(SRC_DIRS),$(wildcard $(dir)*.c))
OBJS:=$(SRCS:.c=.o)
EXEC:=main

.PHONY: all clean

all: run

run: link
	./main

link: $(OBJS)
	$(LD) $^ -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
