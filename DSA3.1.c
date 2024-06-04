#include<stdio.h>
#include<stdlib.h>
void NGE(int *arr,int n)
{
	int flag=0,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			
			if(arr[j]>arr[i])
			{
				printf("%d>%d\n",arr[i],arr[j]);
				break;
			}
			flag=1;
		}
		if(flag==1)
		printf("%d>-1\n",arr[i]);
	}
}
int main()
{
	int n=0,i;
	printf("how many elements?");
	scanf("%d",&n);
	int*arr=(int*)malloc(n*sizeof(int));
	printf("Give the numbers");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	NGE(arr,n);
}
