#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
char x[20];
int fd=open("Test.txt",O_RDWR);
	read(fd,x,16);
printf("%s",x);
return 0;
}
