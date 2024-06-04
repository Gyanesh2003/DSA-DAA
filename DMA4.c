#include<stdio.h>
#include<conio.h>
struct date
{
int day,month,year;
};
struct date take(struct date t)
{
printf("\nEnter the date, month and year::");
scanf("%d%d%d",&t.day,&t.month,&t.year);
return t;
}
void display(struct date t)
{
switch(t.month)
{
case 1:
printf("JANUARY");
break;
case 2:
printf("FEBRUARY");
break;
case 3:
printf("MARCH");
break;
case 4:
printf("APRIL");
break;
case 5:
printf("MAY");
break;
case 6:
printf("JUNE");
break;
case 7:
printf("JULY");
break;
case 8:
printf("AUGUST");
break;
case 9:
printf("SEPTEMBER");
break;
case 10:
printf("OCTOBER");
break;
case 11:
printf("NOVEMBER");
break;
case 12:
printf("DECEMBER");
break;

}
printf("%4d%c%6d",t.day,',',t.year);
}
int validate(struct date t)
{
int leap,i,yr,spy=0;
yr=t.year;
for(i=0;i<2;i++)
{
leap=yr%10;
if(leap!=0)
break;
}
if((i==2)&&(t.year%400==0))
leap=1;
else if(t.year%4==0)
leap=1;
switch(t.month)
{
case 1:
{
if(t.day>31)
{
printf("\nJANUARY has only 31 days.");
spy=1;
}
break;
}
case 2:
{
if((leap==1)&&(t.day>29))
{
printf("\nThis year FEBRUARY has only 29 days.");
spy=1;
}
else if((t.day>28)&&(leap!=1))
{
printf("\nFEBRUARY has only 28 days.");
spy=1;
}
break;
}
case 3:
{
if(t.day>31)
{
printf("\nMARCH has only 31 days.");
spy=1;
}
break;
}
case 4:
{
if(t.day>30)
{
printf("\nAPRIL has only 31 days.");
spy=1;
}
break;
}
case 5:
{
if(t.day>31)
{
printf("\nMAY has only 31 days.");
spy=1;
}
break;
}
case 6:
{
if(t.day>30)
{
printf("\nJUNE has only 30 days.");
spy=1;
}
break;
}
case 7:
{
if(t.day>31)
{
printf("\nJULY has only 31 days.");
spy=1;
}
break;
}
case 8:
{
if(t.day>31)
{
printf("\nAUGUST has only 31 days.");
spy=1;
}
break;
}
case 9:
{
if(t.day>30)
{
printf("\nSEPTEMBER has only 30 days.");
spy=1;
}
break;
}
case 10:
{
if(t.day>31)
{
printf("\nOCTOBER has only 31 days.");
spy=1;
}
break;
}
case 11:
{
if(t.day>30)
{
printf("\nNOVEMBER has only 30 days.");
spy=1;
}
break;
}
case 12:
{
if(t.day>31)
{
printf("\nDECEMBER has only 31 days.");
spy=1;
}
break;
}
}
return spy;
}
void main()
{
int i;
struct date t;
t=take(t);
i=validate(t);
if(i==0)
display(t);
getch();
}
