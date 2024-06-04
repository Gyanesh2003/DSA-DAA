#include<stdio.h>
int main()
{
	int n1=0,n2=1,i,j,next_term;
	printf("enter the term number:");
	scanf("%d",&j);
	printf("the fibonacci number goes on:%d %d",n1,n2);
	for(i=3;i<=j;++i)
	{
		printf("%d ",next_term);
		n1=n2;
		n2=next_term;
		next_term=n1+n2;
	}
	return 0;
}
