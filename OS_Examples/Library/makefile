CC*=

all:	main
	./main
main:		main.o all_fun.o
	$(CC) -o main main.o all_fun.o

main.o:		main.c
	$(CC) -o main.o -c main.c

all_fun.o:	all_fun.c
	$(CC) -o all_fun.o -c all_fun.c

#run:#
#	./$(CC1)#
clean:
	rm -rf *.o
	rm -rf main
