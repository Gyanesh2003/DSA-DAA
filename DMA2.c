#include <stdio.h>
#include <stdlib.h>
typedef struct time{
    int hour;
    int minute;
    int second;
}time;

int main()
{
	int i;
    time* ptr;
    ptr=(time*) malloc(2*sizeof(time));
    for(i=0;i<2;i++)
    {
        printf("GIve the hour, minute and second of timing %d, RESPECTIVELY\n",i+1);
        scanf("%d %d %d",&(ptr+i)->hour,&(ptr+i)->minute,&(ptr+i)->second);
    }

    printf("\nYOUR TIMINGS ARE AS FOLLOWS\n");
    for( i=0;i<2;i++)
    {
        printf("timing %d: %d:%d:%d\n",i+1,(ptr+i)->hour,(ptr+i)->minute,(ptr+i)->second);
    }

    time sum;
    sum.second= (ptr+1)->second+(ptr+0)->second;
    sum.minute=(ptr+0)->minute+(ptr+1)->minute;
    sum.hour=(ptr+0)->hour+(ptr+1)->hour;
    if(sum.second>=59)
       { sum.second=0;
        sum.minute++;}
    if(sum.minute>=59)
        {sum.minute=0;
        sum.hour++;}
    printf("\nThe sum of your timings is %d:%d:%d\n",sum.hour,sum.minute,sum.second);

    time diff;

            diff.second= abs((ptr+0)->second - (ptr+1)->second);
            diff.minute= abs((ptr+0)->minute - (ptr+1)->minute);
            diff.hour= abs((ptr+0)->hour-(ptr+1)->hour);    
    printf("\nThe difference of your timings is %d:%d:%d\n",diff.hour,diff.minute,diff.second);
    return 0;
}
