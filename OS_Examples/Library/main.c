#include<stdio.h>
#include"arith.h"
#include "all.h"
int main()
{
  int a,b;
  printf("Enter values of a and b\n");
  scanf("%d%d", &a,&b);
  printf("Sum=%d\nSubstraction=%d\nMultiply=%d\nDivision=%d\n",addition(a,b),substraction(a,b),divi(a,b),mul(a,b));
  return 0;
}
