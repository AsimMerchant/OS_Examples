#include "head.h"
int count=0;
sem_t inSem,calSem;
int a,b,sum=0;
void *inputFun(void *data)
{
	
	sem_wait(&inSem);
	printf("Enter 2 values\n");
	scanf("%d%d",&a,&b);
	sem_post(&calSem);
}
void *calcFun(void *data)
{
	sem_wait(&calSem);
	sum=a+b;
	printf("Sum=%d\n",sum);
	sem_post(&inSem);	
}
int main()
{

	
	pthread_t inputThread,calcThread;
	
	sem_init(&inSem,0,1);
	sem_init(&calSem,0,0);
/*Below 2 satement is responsible for deadlock and can be solved by above 2 statements*/	
	/*sem_init(&inSem,0,0);
	sem_init(&calSem,0,0);*/
	
	pthread_create(&inputThread,NULL,inputFun,NULL);
	pthread_create(&calcThread,NULL,calcFun,NULL);

	pthread_join(inputThread,NULL);
	pthread_join(calcThread,NULL);

	sem_destroy(&inSem);
	sem_destroy(&calSem);
	return 0;
}
