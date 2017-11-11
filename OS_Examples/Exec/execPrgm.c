#include<unistd.h>
#include<string.h>
#include<stdio.h>
#define MAX 128
int main()
{
	char a[MAX],path[MAX],b[MAX]={'\0'};
	char t;
	pid_t;
	fork()printf("MYSHELL\n");	
	scanf("%s%s",a,b);
	strcpy(path,"/bin/");
	int i=0;
	strcat(path,a);
	execl(path,a,b,NULL);
	return 0;
}
