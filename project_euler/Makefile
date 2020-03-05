CC=g++
CFLAGS=-O3 -Wall -g -Ilibs
#-fdiagnostics-color

SRCS = $(wildcard *.cc)

PROGS = $(patsubst %.cc,%,$(SRCS))
# PROGS = $(SRCS:.cc=.out)

all: $(PROGS)

e27: e27.cc libs/primes.h libs/primes.cc
	$(CC) $(CFLAGS) libs/primes.cc -o $@ $<

e41: e41.cc libs/primes.h libs/primes.cc
	$(CC) $(CFLAGS) libs/primes.cc -o $@ $<

%: %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
