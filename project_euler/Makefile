CC=g++
CFLAGS=-O3 -Wall -g -Ilibs
#-fdiagnostics-color

SRCS = $(wildcard *.cc)

PROGS = $(patsubst %.cc,%,$(SRCS))
# PROGS = $(SRCS:.cc=.out)

all: $(PROGS)

%: %.cc
	$(CC) $(CFLAGS) libs/primes.cc -o $@ $<

clean:
	rm -f $(PROGS)
