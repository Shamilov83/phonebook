
#% make CFLAGS = -g


CC:=gcc

all:exefile

exefile: main.o  SvSpisok.o 
	$(CC) main.o SvSpisok.o -o  exefile

SvSpisok.o: SvSpisok.c
	$(CC) -c SvSpisok.c
main.o: main.c
	$(CC) -c main.c

clear: 
	rm -rf *.o
