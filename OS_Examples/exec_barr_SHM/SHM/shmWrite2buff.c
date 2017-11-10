#include "head.h"
int main ()
{
	sem_t *semSHM;
	int *data;
	int fd;
	semSHM=sem_open("semShare",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR,0);
	sem_close(semSHM);
	fd=shm_open("sharedMem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int*));
	data=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	*data=10;
	sem_wait(semSHM);
	shm_unlink("sharedMem");
	sem_destroy(semSHM);
	return 0;
}
