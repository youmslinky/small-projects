CC=gcc
CFLAGS=-O3 -Wall -g

SRCS = $(wildcard *.cc)

OBJECTS = $(patsubst %.cc,%.o,$(SRCS))

all: main

main: $(OBJECTS)
	gcc $(OBJECTS) -o main

%: %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f main $(OBJECTS)
