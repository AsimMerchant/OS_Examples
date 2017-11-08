#include <stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
int main()
{
  int i;
  if(fork())
  {
    printf("1\n");
	i++;
    sleep(2);

    printf("2\n");
	i++;
    sleep(2);
  }
  else
  {
    printf("3");
	i++;
    sleep(2);

    printf("4");
    sleep(2);

  }
}
