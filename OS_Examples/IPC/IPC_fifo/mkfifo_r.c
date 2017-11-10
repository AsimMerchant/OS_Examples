#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int st_read,st_write,fd_read,fd_write;
	int data[2];
	int sum;
/*here i read the data that was sent from other process*/
	fd_read=open("Comm_write",O_RDONLY);
	read(fd_read,data,8);
	close(fd_read);		
/*here i close fd_read after reading*/
	sum=data[0]+data[1];
/*here i write data in the fifo*/
	fd_write=open("Comm_read",O_WRONLY);
	write(fd_write,&sum,4);	
	close(fd_write);
/*here i stop writing and close fd_write*/
	return 0;
}
