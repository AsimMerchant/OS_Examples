#include<stdio.h>
#include "basicMath.h"
int main()
{
  int a,b;
  printf("Enter values of a and b\n");
  scanf("%d%d", &a,&b);
  printf("Sum=%d\nSubstraction=%d\nMultiply=%d\nDivision=%d\n",add(a,b),sub(a,b),mul(a,b),divi(a,b));
  return 0;
}
