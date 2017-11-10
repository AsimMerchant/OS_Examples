#include<unistd.h>
#include<stdio.h>
#include<string.h>
#define MAX 128
int main()
{
	char *a[MAX],path[MAX],b[MAX];
	pid_t x;
	int i=0;
	for (i=0;i<MAX;i++)
	a[i]=(char *)malloc(sizeof(char)*MAX);
	printf("MYSHELL\n");
	for (i=0;i<MAX;i++)	
	scanf("%s",*(a+i));
	strcpy(path,"/bin/");
	while(a[i]!='\0' && a[i]!=' ')
	{
		b[i]=a[i];
		i++;
	}
	strcat(path,b);
	printf("%s\n",a);
	x=fork ();
	if (x==0)
	{
			execv(path,a);
	}
 else
 {
	 printf("again back in parent\n");
 }
	return 0;
}
