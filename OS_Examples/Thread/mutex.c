#include "head.h"
int count=0;
pthread_mutex_t inSem/*=PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP*/;
int a,b;
void *calcFun(void *data)
{
	int sum=0;
	pthread_mutex_lock(&inSem);
	sum=a+b;
	printf("Sum=%d\n",sum);
	pthread_mutex_unlock(&inSem);	
}

void *inputFun(void *data)
{
	pthread_mutex_lock(&inSem);	
	printf("Enter 2 values\n");
	scanf("%d%d",&a,&b);
	pthread_mutex_unlock(&inSem);
}

int main()
{

	
	pthread_t inputThread,calcThread;
		
	pthread_mutex_init(&inSem,NULL);
	
	pthread_create(&inputThread,NULL,inputFun,NULL);
	pthread_create(&calcThread,NULL,calcFun,NULL);

	pthread_join(inputThread,NULL);
	pthread_join(calcThread,NULL);

	pthread_mutex_destroy(&inSem);

	return 0;
}
