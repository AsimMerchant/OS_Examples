#include "head.h"
int a=10,b=5;

sem_t countingSem;
pthread_t addThread,subThread,mulThread,divThread,sqThread;
void *addFun(void *data)
{
  int sum;
  sem_wait(&countingSem);
  sum=a+b;
  printf("1:Sum is %d\n",sum);
  sem_post(&countingSem);
}

void *subFun(void *data)
{
  int sub;
  sem_wait(&countingSem);
  sub=a-b;
  printf("2:Substraction is %d\n",sub);
  sem_post(&countingSem);
}

void *mulFun(void *data)
{
  int mul;
  sem_wait(&countingSem);
  mul=a*b;
  printf("3:Multiplication is %d\n",mul);
  sem_post(&countingSem);
}

void *divFun(void *data)
{
  int di;
  sem_wait(&countingSem);
  di=a/b;
  printf("4:Division is %d\n",di);
  sem_post(&countingSem);
}

void *sqreFun(void *data)
{
  int sqa,sqb;
  sem_wait(&countingSem);
  sqa=a*a;
  sqb=b*b;
  printf("5:Square of a is %d and b is %d\n",sqa,sqb);
  sem_post(&countingSem);
}

int main()
{
  sem_init(&countingSem,0,3);

  pthread_create(&addThread,NULL,addFun,NULL);
  pthread_create(&subThread,NULL,subFun,NULL);
  pthread_create(&mulThread,NULL,mulFun,NULL);
  pthread_create(&divThread,NULL,divFun,NULL);
  pthread_create(&sqThread,NULL,sqreFun,NULL);

  pthread_join(addThread,NULL);
  pthread_join(subThread,NULL);
  pthread_join(mulThread,NULL);
  pthread_join(divThread,NULL);
  pthread_join(sqThread,NULL);

  sem_destroy(&countingSem);
  return 0;
}
