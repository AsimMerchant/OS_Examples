#include "head.h"
pthread_barrier_t barrThread;
pthread_t serialThread,lcdThread,sensorThread;

void *Serial(void *data)
{
	printf("initializing serial\n");
	pthread_barrier_wait(&barrThread);
	printf("now sending data to serial\n");
}

void *LCD(void *data)
{
	printf("initializing LCD\n");
	pthread_barrier_wait(&barrThread);
	printf("now sending data to LCD\n");
}

void *Sensor(void *data)
{
	printf("initializing sensor\n");
	pthread_barrier_wait(&barrThread);
	printf("now sensing data from SENSOR\n");
}

int main ()
{

	pthread_barrier_init(&barrThread,NULL,3);  
	
	pthread_create(&serialThread,NULL,Serial,NULL);
	pthread_create(&lcdThread,NULL,LCD,NULL);	
	pthread_create(&sensorThread,NULL,Sensor,NULL);
	
	
	pthread_join(serialThread,NULL);
	pthread_join(lcdThread,NULL);
	pthread_join(sensorThread,NULL);

	pthread_barrier_destroy(&barrThread);

}
