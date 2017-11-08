CC*=

all:	main
	./main
main:		main.o basicMath.o
	$(CC) -o main main.o basicMath.o

main.o:		main.c
	$(CC) -o main.o -c main.c

basicMath.o:	basicMath.c
	$(CC) -o basicMath.o -c basicMath.c

#run:#
#	./$(CC1)#
clean:
	rm -rf *.o
	rm -rf main
