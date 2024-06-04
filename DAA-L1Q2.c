#include<stdio.h>
int main()
{
	int N,i;
	printf("enter the size of an array");
	scanf("%d",&N);
	int arr[N],prefixSum[N];
	printf("Enter the elements of the array:");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	prefixSum[0]=arr[0];
	for(i=1;i<N;i++)
	{
		prefixSum[i]=prefixSum[i-1]+arr[i];
	}
	printf("Output array:");
	for(i=0;i<N;i++)
	{
		printf("%d",prefixSum[i]);
	}
	printf("\n");
	return 0;
}
