#include<stdio.h>
#include "avg.h"
int main ()
{
  int a,b,c,d,e;
  printf("enter five numbers\n");
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
  printf("average=%d\n",average(a,b,c,d,e));
  return 0;
}
