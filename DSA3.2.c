#include<stdio.h>
int main()
{
	int *ptr,i,j,n,a,b,t,f=0;
	printf("enter a number");
	scanf("%d",&n);
	ptr=(int*)malloc(n*sizeof(int));
	printf("enter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	for(i=0;i<n;i++)
	{
	for(j=0;j<i;j++)
	{
		if((*ptr+i)<*(ptr+j))
		{
			t=*(ptr+i);
			*(ptr+i)=*(ptr+j);
			*(ptr+j)=t;
		}
	}
}
printf("enter the elements to search between");
scanf("%d %d",&a,&b);
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if((*ptr+i)==a&&*(ptr+j)==b)
		f++;
	}
}
if(f>0)
{
	printf("the number are:");
	for(i=a-1;i<b;i++)
	{
	printf("%d ",*(ptr+i));
    }
}
else
{
	printf("INVALID INPUT");
	free(ptr);
	return 0;
}
}
