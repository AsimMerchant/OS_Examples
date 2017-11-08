A*=

all:	main
	#./main
main:	main.o add.o sub.o mul.o div.o
	$(A) -o main main.o add.o sub.o mul.o div.o
main.o:	main.c
	$(A) -o main.o -c main.c
add.o:	add.c
	$(A) -o add.o -c add.c
sub.o:	sub.c
	$(A) -o sub.o -c sub.c
mul.o:	mul.c
	$(A) -o mul.o -c mul.c
div.o:	div.c
	$(A) -o div.o -c div.c

#$ (CC) -MM main.c add.c sub.c mul.c div.c
clean:
	rm -rf *.o
	rm -rf main
