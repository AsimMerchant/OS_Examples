#include "head.h"
int main ()
{
	int *data;
	int fd;
	fd=shm_open("sharedMem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int*));
	data=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	printf("%d\n",*data);
	shm_unlink("sharedMem");
	return 0;
}
