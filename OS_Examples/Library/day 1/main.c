#include<stdio.h>
#include "1.h"

int main ()
{

	int x,y,ch;
	printf("enter two numbers\n");
	scanf("%d%d",&x,&y);

	printf("enter your choice\n1 add\n2 subs\n3 mul\n4 div\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
	
		case 1:
			printf("%d\n",add(x,y));
			
			break;
	
		case 2:
			printf("%d\n",sub(x,y));
			
			break;
		case 3:
			printf("%d\n",mul(x,y));
			
			break;
		case 4:
			printf("%d\n",div(x,y));
			
			break;

		default:
			printf("invalid entry\n");
			break;
	}
}
