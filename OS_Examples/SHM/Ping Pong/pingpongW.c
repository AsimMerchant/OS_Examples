#include "head.h"
int main ()
{
	sem_t *semSHM,*semSHMW,*semSHMW1;
	int *data,newdata,originaldata;
  int *tempBuffer=NULL;
	int fd,fdBuffer;

	semSHM=sem_open("semRead",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);
  semSHMW=sem_open("semWrite",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);
	semSHMW1=sem_open("semWrite1",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);


  fd=shm_open("sharedMem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int*));
	data=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

  fdBuffer=shm_open("sharedBuffer",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
  ftruncate(fdBuffer,sizeof(int*));
  tempBuffer=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fdBuffer,0);

  printf("Enter first data\n");
  scanf("%d",&originaldata);
  *data=originaldata;
  sem_post(semSHMW);
	sem_wait(semSHM);
  printf("Enter second data\n");
  scanf("%d",&newdata);
  //*tempBuffer=newdata;
  //shm_unlink("sharedMem");
  *data=newdata;
	sem_post(semSHMW1);

	return 0;
}
