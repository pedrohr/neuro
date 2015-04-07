CFLAGS=-O2 -Wall
CC=gcc

compile: spar queue list slist main.c
	$(CC) main.c queue.o list.o slist.o sparse.o -o neuro $(CFLAGS)

spar: sparse.c sparse.h
	$(CC) -c sparse.c -o sparse.o $(CFLAGS)

list: queue.h list.c
	$(CC) -c list.c -o list.o $(CFLAGS)

slist: slist.h slist.c
	$(CC) -c slist.c -o slist.o $(CFLAGS)

queue: queue.h queue.c
	$(CC) -c queue.c -o queue.o $(CFLAGS)

clean:
	rm *.o
	rm *~
