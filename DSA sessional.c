/*write a program to arrange the elements of an array in descending order using bubble sort*/
#include <stdio.h>
void main (){
   int num[20];
   int i, j, a, n;
   printf("enter number of elements in an array");
   scanf("%d", &n);
   printf("Enter the elements");
   for (i = 0; i < n; ++i)
      scanf("%d", &num[i]);
   for (i = 0; i < n; ++i){
      for (j = i + 1; j < n; ++j){
         if (num[i] < num[j]){
            a = num[i];
            num[i] = num[j];
            num[j] = a;
         }
      }
   }
   for (i = 0; i < n; ++i){
      printf("\t%d", num[i]);
   }
}