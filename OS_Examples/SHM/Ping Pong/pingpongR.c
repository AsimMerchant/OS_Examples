#include "head.h"
int main ()
{
	sem_t *semSHM,*semSHMW,*semSHMW1;
	int *data;
	int fd;
	semSHM=sem_open("semRead",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);
  //sem_close(semSHM);
  semSHMW=sem_open("semWrite",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);
  //sem_close(semSHMW);
  semSHMW1=sem_open("semWrite1",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);

  sem_wait(semSHMW);

  fd=shm_open("sharedMem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int*));
	data=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  printf("%d\n",*data);
 	sem_post(semSHM);
 	sem_wait(semSHMW1);
	//sleep(5);
	fd=shm_open("sharedMem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int*));
	data=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  printf("%d\n",*data);
	return 0;
}
