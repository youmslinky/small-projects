CC=g++
CFLAGS=-Wall -g
#-fdiagnostics-color

SRCS = $(wildcard *.cc)

PROGS = $(patsubst %.cc,%,$(SRCS))
# PROGS = $(SRCS:.cc=.out)

all: $(PROGS)

%: %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
