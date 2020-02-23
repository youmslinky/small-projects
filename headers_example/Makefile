CC=g++
CFLAGS=-g -c -Wall

all: main

hello: hello.cc
	$(CC) $(CFALGS) -o hello hello.cc
main: main.o primes.o
	$(CC) -o main main.o primes.o
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
#main.o: main.cc
#	$(CC) $(CFLAGS) -c main.cc
#primes.o: primes.cc
#	$(CC) $(CFLAGS) -c primes.cc
clean:
	rm -fr *.o main
