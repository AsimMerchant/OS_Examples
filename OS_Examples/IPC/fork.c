#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
	printf("Before fork parent=%d, process id=%d ",getppid(),getpid());
	fork();
	printf("After fork parent=%d, process id=%d ",getppid(),getpid());
	fork();
	printf("After second fork parent=%d, process id=%d ",getppid(),getpid());
}
