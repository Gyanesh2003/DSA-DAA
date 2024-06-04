#include <stdio.h>
void swap_value(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("The value of a and b is %d & %d respectively(swapped by passing just the values)\n",a,b);
}
int swap_address(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}
int main()
{
    int x=12,y=21;
    int *P=&x;
    int *Q=&y;
    printf("The values BEFORE swap(pass by value)==> %d & %d\n",x,y);
    swap_value(x,y);
    printf("\n\n\n\n");
    printf("\nThe values after swap %d & %d",x,y);
    printf("\nThe values before swap %d & %d",x,y);
    printf("\n\n\n\n");
    swap_address(P,Q);
    printf("The values AFTER swap(pass by value)==> %d & %d\n",x,y);
    printf("\n\n\n\n");
    return 0;
}
