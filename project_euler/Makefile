CC=g++
#CFLAGS=-Wall 
#-fdiagnostics-color

SRCS = $(wildcard *.cc)

PROGS = $(patsubst %.cc,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -f $(PROGS)
