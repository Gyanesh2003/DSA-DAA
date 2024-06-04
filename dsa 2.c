#include<stdio.h>
int main(){
 int arr[100], n,i;
 printf("Enter the number of elements: ");
 scanf("%d",&n);
 printf("Enter the elements:");
 for (i=0;i<n;i++){
  scanf("%d",&arr[i]);
 }
 int t,j;
 printf("\nDescending order: ");
 for(i=0;i<n;i++){
  for(j=0;j<5;j++){
   if(arr[i]>arr[j]){
    t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
   }
  }
 }
 for(i=0;i<n;i++){
  printf("%d ",arr[i]);
 }
 printf("\nElements having sum nine: ");
 for(i=0;i<n;i++){
  if(arr[i]%9==0){
   printf("%d ",arr[i]);
  }
 }
}
