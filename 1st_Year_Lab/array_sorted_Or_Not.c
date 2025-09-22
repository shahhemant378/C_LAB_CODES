#include<stdio.h>
#include<stdbool.h>

bool isSortedOrNot(int *arr,int size){
int i;
bool isSorted=true;
for(i=0;i<size;i++){
    if(*(arr+i+1)<*(arr+i)){ isSorted=false; break;}
}
return isSorted;
}
void main(){
    //WAP that takes one 1D array as input and prints whether the array is sorted or not 
    int n;
    printf("Enter the size of array");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        printf("Enter %d index value:-",i);
        scanf("%d",&arr[i]);
    }
    if(isSortedOrNot(arr,n)){
        printf("\nThe array is sorted");
    }else{
        printf("\nThe array is not sorted");
    }
}
