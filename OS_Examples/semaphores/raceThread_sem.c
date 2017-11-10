#include "head.h"
int count=0;
sem_t countSem;
/*Overcoming race condition using semaphores*/
void *incFun(void *data)
{
	while(1)
	{
		sem_wait(&countSem);
		count++;
		printf("inc=%d\n",count);
		sem_post(&countSem);
	}
}
void *decFun(void *data)
{
	while(1)
	{
		sem_wait(&countSem);
		count--;
		printf("dec=%d\n",count);
		sem_post(&countSem);
	}
}
int main()
{

	
	pthread_t incThread,decThread;
	
	sem_init(&countSem,0,1);
	pthread_create(&incThread,NULL,incFun,NULL);
	pthread_create(&decThread,NULL,decFun,NULL);
	pthread_join(incThread,NULL);
	pthread_join(decThread,NULL);
	sem_destroy(&countSem);
	return 0;
}
