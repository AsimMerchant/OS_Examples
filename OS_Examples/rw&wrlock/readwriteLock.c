#include "head.h"
pthread_rwlock_t rwLock ;
int count=0;
void *countWrite(void *data)
{	
	printf("Writing: before lock\n");
	pthread_rwlock_wrlock (&rwLock);
	count++;
	printf("Writing: count\n");
	pthread_rwlock_unlock (&rwLock);
	printf("Writing: after lock\n");
}
void *countRead_LCD(void *data)
{
	printf("Send_LCD: before lock\n");
	pthread_rwlock_rdlock (&rwLock);
	printf("Send count to LCD\n");
	pthread_rwlock_unlock (&rwLock);
	printf("Send_LCD: after lock\n");
}

void *countRead_SERIAL(void *data)
{
	printf("Send_SERIAL: before lock\n");
	pthread_rwlock_rdlock(&rwLock);
	printf("Send count to SERIAL\n");
	pthread_rwlock_unlock (&rwLock);
	printf("Send_SERIAL: after lock\n");
}
int main()
{

	
	pthread_t writeThread,readLCDThread,readSERIALThread;
	
	pthread_rwlock_init(&rwLock,NULL);
	
	pthread_create(&writeThread,NULL,countWrite,NULL);
	pthread_create(&readLCDThread,NULL,countRead_LCD,NULL);
	pthread_create(&readSERIALThread,NULL,countRead_SERIAL,NULL);
	
	pthread_join(writeThread,NULL);
	pthread_join(readLCDThread,NULL);
	pthread_join(readSERIALThread,NULL);

	pthread_rwlock_destroy(&rwLock);
	
	return 0;
}
