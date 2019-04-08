FLAGS := -std=c99

all: prog

prog: main.o coder.o command.o
	gcc -Wall main.o coder.o command.c -o main $(FLAGS)
main.o: main.c
	gcc -Wall -c main.c -o main.o $(FLAGS)
coder.o: coder.c
	gcc -Wall -c coder.c -o coder.o $(FLAGS)
command.o: command.c
	gcc -Wall -c command.c -o command.o $(FLAGS)

clean:
	rm -f *.o
	main
