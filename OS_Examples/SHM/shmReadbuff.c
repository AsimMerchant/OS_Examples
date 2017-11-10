#include "head.h"
int main ()
{
	sem_t *semSHM;
	int *data;
	int fd;
	semSHM=sem_open("semShare",O_CREAT|O_RDONLY,S_IRUSR|S_IWUSR,0);
	fd=shm_open("sharedMem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int*));
	data=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	printf("%d\n",*data);
	sem_post(semSHM);
	shm_unlink("sharedMem");
	sem_close(semSHM);
	return 0;
}
