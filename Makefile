CC:=gcc
CFLAGS:=-Wall -O3
LD:=gcc
LDFLAGS:=-lSDL2 -lSDL2_image -lSDL2_ttf

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
	make clean

clean:
	rm -f $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
