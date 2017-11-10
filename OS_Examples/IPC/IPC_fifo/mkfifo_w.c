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
	printf("Enter 2 data to send to another process\n");
	scanf("%d%d",&data[0],&data[1]);
/*here i make fifo for read and write*/
	st_write=mkfifo("Comm_write",S_IRUSR|S_IWUSR);
	st_read=mkfifo("Comm_read",S_IRUSR|S_IWUSR);
/*here i write data in the com_write fifo*/
	fd_write=open("Comm_write",O_WRONLY);
	write(fd_write,data,8);	
	close(fd_write);
/*here i stop writing and close fd_write*/
/*here i read the data that was manipulated in the other process*/
	fd_read=open("Comm_read",O_RDONLY);
	read(fd_read,&sum,4);
	close(fd_read);
/*here i close fd_read after reading*/
	printf("Sum is %d\n",sum);	
	return 0;
}
