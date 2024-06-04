#include<stdio.h>
void printDistinctElements(int array[], int size) {
   int i, j, array1[size], temp, count = 0;
   for(i = 0; i < size; i++) {
      for(j = i+1; j < size; j++) {
         if(array[i] == array[j]) {
            break;
         }
      }
      if(j == size) {
         array1[count++] = array[i];
      }
   }   for ( i = 0; i < count-1; i++) {
      for ( j = i+1; j < count; j++) {
         if(array1[i]>array1[j]) {
            temp = array1[i];
            array1[i] = array1[j];
            array1[j] = temp;
         }
      }
   }
   for ( i = 0; i < count; ++i) {
      printf("%d ", array1[i]);
   }
}
int main() {
   int arr[] = {5, 64, 6, 2, 4, 10, 1, 8, 7, 0};
   int n = sizeof(arr)/sizeof(arr[0]);
   printDistinctElements(arr, n);
   return 0;
}
