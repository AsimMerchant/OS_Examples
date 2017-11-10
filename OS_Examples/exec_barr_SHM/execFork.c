#include<unistd.h>
#include<stdio.h>
#define MAX 128
int main()
{
	char a[MAX],path[MAX],b[MAX];
	pid_t x;
	printf("MYSHELL\n");
	scanf("%s%s",a,b);
	strcpy(path,"/bin/");
	strcat(path,a);
	x=fork ();
	if (x==0)
	{
			execl(path,a,b,NULL);
	}
 else
 {
	 printf("again back in parent\n");
 }
	return 0;
}
