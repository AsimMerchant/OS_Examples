#include <pthread.h>
#include <stdio.h>
int *myInc(int *data)
{
	int *i;
	i=(int*)malloc(sizeof(int));
	*i=*data+1;
	return i;
}
int *mydec(int *data1)
{
	int *i;
	i=(int*)malloc(sizeof(int));
	*i=*data1-1;
	return i;
}
int main()
{
	pthread_t tid_inc,tid_dec;
	int st_inc,st_dec;
	int a,*inc,*dec;
	printf("enter a number\n");
	scanf("%d",&a);
	st_inc=pthread_create(&tid_inc,NULL,myInc,&a);
	//perror("1");	
	st_dec=pthread_create(&tid_dec,NULL,mydec,&a);
	//perror("2");
	pthread_join(tid_inc,&inc);
	//perror("3");
	pthread_join(tid_dec,&dec);
	//perror("4");
	printf("inc = %d\n",*inc);	
	printf("dec=%d\n",*dec);
	return 0;
}
