#include "head.h"
int complete=0;
//int a;
pthread_mutex_t comMutex;
pthread_cond_t completeCond;
void *completeCheck(void *data)
{
	pthread_mutex_lock(&comMutex);
	printf("CHECK\n");
	while(complete==0)
	{
		printf("Wating...\n");
		pthread_cond_wait(&completeCond,&comMutex);
	}
	pthread_mutex_unlock(&comMutex);
	printf("CHECK RELEASE\n");
}
void *completeUpdate(void *data)
{
	pthread_mutex_lock(&comMutex);
	printf("UPDATE\n");
	complete=1;
	pthread_mutex_unlock(&comMutex);
	printf("UPDATE RELEASE\n");
	pthread_cond_signal(&completeCond);
}
int main()
{

	
	pthread_t checkThread,updateThread;
	
	pthread_mutex_init(&comMutex,NULL);
	pthread_cond_init(&completeCond,NULL);
	
	pthread_create(&checkThread,NULL,completeCheck,NULL);
	pthread_create(&updateThread,NULL,completeUpdate,NULL);
	
	pthread_join(checkThread,NULL);
	pthread_join(updateThread,NULL);

	pthread_mutex_destroy(&comMutex);
	pthread_cond_destroy(&completeCond);
	
	return 0;
}
