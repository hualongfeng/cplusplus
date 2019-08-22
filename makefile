#SRC = $(shell ls *.cc)
SRC = $(wildcard *.c *.cc)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cc,%.o,$(SRC)))
XX = g++
CC = gcc
CFLAGS = -Wall -O -g
TARGET = a.out

$(TARGET): $(OBJS)
	$(XX) -o $@ $^

%.o: %.cc
	$(XX) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test *.o
