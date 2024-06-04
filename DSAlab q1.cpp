#include<stdio.h>

/* Declaration of structure */
struct student
{
 char name[30];
 int roll;
 float marks;
};

int main()
{
 /* Declaration of array of structure */
 struct student s[3];
 int i;
 
 for(i=0;i< 3;i++)
 {
  printf("Enter name, roll and marks of student:\n");
  scanf("%s%d%f",s[i].name, &s[i].roll, &s[i].marks);
 }
 printf("Inputted details are:\n");
 for(i=0;i< 3;i++)
 {
  printf("Name: %s\n",s[i].name);
  printf("Roll: %d\n", s[i].roll);
  printf("Marks: %0.2f\n\n", s[i].marks);
 }
 return 0;
}
