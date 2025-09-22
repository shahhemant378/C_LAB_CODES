// Online C compiler to run C program online
#include <stdio.h>
#include<limits.h>


int findLargest(int *arr,int k,int size){
  int largest=INT_MIN;
  int last_index=-1;
  int i,j;
  for(i=0;i<k;i++){
    for(j=0;j<size;j++){
        if(arr[j]>largest){
            largest=arr[j];
            last_index=j;
        }
        if(arr[j]==largest)
        arr[j]=INT_MIN;
    }
    if(i<k-1)
    largest=INT_MIN;
    arr[last_index]=INT_MIN;
  }
  return largest;
}

void main() {
    // Write C code here
   int arr[5];
   int i;
   for(i=0;i<5;i++){
       scanf("%d",&arr[i]);
   }
// int arr[5]={5,4,3,2,1};
   printf("The second Largest is: %d",findLargest(arr,2,5));
}