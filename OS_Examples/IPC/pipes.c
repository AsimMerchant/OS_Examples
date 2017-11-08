#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
int pipefd[2],x,c_pipefd[2],y;
int p[2],q[2],r,s;
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
      read(pipefd[0],p,8);
      r=p[0]+p[1];
      write(c_pipefd[1],&r,4);
    }
    else
    {
      q[0]=10;
      q[1]=20;
      write(pipefd[1],q,8);
      read(c_pipefd[0],&s,4);
      printf("Data received from child is %d\n",s);
    }
  }
}
else
perror("Pipe failure\n");
  return 0;
}
