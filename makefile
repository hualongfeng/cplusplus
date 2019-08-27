#SRC = $(shell ls *.cc)
SRC = $(wildcard *.c *.cc)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cc,%.o,$(SRC)))
DEPS = $(patsubst %.o, %d, $(OBJS))  
XX = g++
CC = gcc
CFLAGS = -Wall -g 
TARGET = a.out

$(TARGET): $(OBJS)
	$(XX) -o $@ $^

%.o: %.cc
	$(XX) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)        

clean:
	rm -f *.o $(TARGET)
