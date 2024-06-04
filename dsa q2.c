#include <stdio.h>
int linearSearch(int arr[], int size, int x) {
    int rec;
 
    size--;
 
    if (size >= 0) {
        if (arr[size] == x)
            return size;
        else{
            rec = linearSearch(arr, size, x);
        }
    }
    else
        return -1;
 
    return rec;
}
int recursiveBinarySearch(int array[], int start_index, int end_index, int element){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return recursiveBinarySearch(array, start_index, middle-1, element);
      return recursiveBinarySearch(array, middle+1, end_index, element);
   }
   return -1;
}
int main(){
    int a[] = {2,45,78,80,90};
    int n = sizeof(a) / sizeof(int);
    printf("element 78 found at index : %d\n", linearSearch(a, n, 78));
    printf("element 90 found at index : %d\n", recursiveBinarySearch(a, 0 , n-1, 90));
    return 0;
}
