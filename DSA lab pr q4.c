#include<stdio.h>
int main()
{
	int  original_num,remainder,result=0,num;
	printf("enter the number:");
	scanf("%d",&num);
	original_num=num;
	while(original_num!=0)
	{
		remainder=original_num%10;
		result+=remainder*remainder*remainder;
		original_num/=10;
	 }
	 if(result=num)
	 	printf("%d is a ARMSTRONG number\n",num);
	else 
	    printf("%d is not a ARMSTONG number\n",num);
	  return 0;
}
