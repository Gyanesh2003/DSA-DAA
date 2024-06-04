#include<stdio.h>
int main()
{
	int g,h,i;
	printf("enter three numbers:");
	scanf("%d %d %d",&g,&h,&i);
	if(g>h>i)
	{
		printf("%d %d %d is a maximum number",g,h,i);
	}
    return 0;
}
