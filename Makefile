CC=g++
CFLAGS=-c -Wall

all: DZ1

DZ1: main.o Sorts.o
	$(CC) main.o Sorts.o -o DZ1

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Sorts.o: Sorts.cpp
	$(CC) $(CFLAGS) Sorts.cpp

clean:
	rm -rf *.o DZ1