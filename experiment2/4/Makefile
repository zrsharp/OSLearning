CC = gcc
INCLUDE = ./include
SRC = ./src
CFLAGS = -g -Wall -ansi

main.out: main.o 2.o 3.o
	gcc main.o 2.o 3.o -o main.out
	rm *.o
main.o: main.c $(INCLUDE)/a.h
	gcc -c main.c
2.o: $(SRC)/2.c $(INCLUDE)/a.h $(INCLUDE)/b.h
	gcc -c 2.c
3.o: $(SRC)/3.c $(INCLUDE)/b.h $(INCLUDE)/c.h
	gcc -c 3.c


