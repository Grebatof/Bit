FLAGS := -std=c99

all: prog

prog: main.o task1.o
	gcc -Wall main.o task1.o -o main $(FLAGS)
main.o: main.c
	gcc -Wall -c main.c -o main.o $(FLAGS)
task1.o: task1.c
	gcc -Wall -c task1.c -o task1.o $(FLAGS)

clean:
	rm -f *.o
	main
