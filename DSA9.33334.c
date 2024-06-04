#include <stdio.h>
#define n 5
int q[n];
int f=-1 , r=-1;
void enqueRear(int x)
{
    if((f==0 && r==n-1) || (f==r+1))
        printf("overflow\n");
    else if(f==-1 && r==-1){
        f=r=0;
        q[r] = x;
    }
    else if(r==n-1)
    {
        r=0;
        q[r]= x;
    }
    else{
        r++;
        q[r] = x;
    }
}
void dequeFront()
{
    int val;
    if(f==-1 && r==-1)
    {
        printf("underflow\n");
    }
    else
    {
        val = q[f];
        if(f==n-1)
            f==0;
        else if(f==r)
            f=r=-1;
        else    
            f++;
        printf("dequed element from front is : %d \n" , val);
    }
}

void enqueFront(int x)
{
    if((f==0 && r==n-1) || (f==r+1))
        printf("overflow\n");
    else if(f==-1 && r==-1){
        f=r=0;
        q[f] = x;
    }
    else if(f==0)
    {
        r=n-1;
        q[f]= x;
    }
    else{
        f--;
        q[f] = x;
    }
}
void display()
{
    if(f==1 && r==-1)
        printf("queue is empty \n");
    else
    {
        printf("Displaying queue : \n");
        int i = f;
        while(i!=r)
        {
            printf("%d ", q[i]);
            i= (i+1)%n;
        }
        printf("%d " , q[i]);
        printf("\n");
    }
}
int main()
{
    enqueRear(22);
    enqueRear(12);
    enqueRear(46);
    enqueRear(2);
    display();
    printf("\n");
    dequeFront();
    display();
    enqueFront(45);
    display();
    return 0;
}
