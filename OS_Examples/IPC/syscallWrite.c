#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX 128
int main()
{
char data[MAX];
int fd=open("Test.txt",O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	write(fd,"I am batman",MAX);
return 0;
}
