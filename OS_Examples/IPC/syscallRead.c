#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX 128
int main()
{
char data[MAX];
int fd=open("Test.txt",O_RDONLY);
	read(fd,data,MAX);
	printf("%s\n",data);
return 0;
}
