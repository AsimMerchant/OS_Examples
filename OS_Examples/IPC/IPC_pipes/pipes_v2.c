#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_SIZE sizeof(long unsigned int)
#define MAX_ARRAY 2*sizeof(long unsigned int)
int main() {
int pipefd[2],x,c_pipefd[2],y;
long unsigned int p[2],q[2],r,s;
pid_t pid;
x=pipe(pipefd);
perror("1");
y=pipe(c_pipefd);
perror("2");
if(x==0 && y==0)
{
  printf("Pipe to transfer data from parent to child created succesfully\n");
  pid=fork();
  if(pid==-1)
  perror("Fork failure\n");
  else
  {
    if(pid==0)//here you are in child process
    {
      read(pipefd[0],p,MAX_ARRAY);
      r=p[0]+p[1];
      write(c_pipefd[1],&r,MAX_SIZE);
    }
    else
    {
      printf("Enter 2 values\n");
      scanf("%lu%lu",&q[0],&q[1]);
      write(pipefd[1],q,MAX_ARRAY);
      read(c_pipefd[0],&s,MAX_SIZE);
      printf("Data received from child is %lu\n",s);
    }
  }
}
else
perror("Pipe failure\n");
  return 0;
}
