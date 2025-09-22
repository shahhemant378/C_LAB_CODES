#include<stdio.h>
#include<stdbool.h>

void swap(int *arr,int first,int second){
int temp;
temp=*(arr+first);
*(arr+first)=*(arr+second);
*(arr+second)=temp;
}
void main(){
    //Write a function that takes one 1D array as input and swap the content of the array as per user
    int n;
    int first;
    int second;
    printf("Enter the size of array");
    scanf("%d",&n);

    
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        printf("Enter %d index value:-",i); //taking input value
        scanf("%d",&arr[i]);
    }


    //checking for indices
    printf("Enter the two swapping index");
    scanf("%d%d",&first,&second);
    if(first<0 || second>n-1){  //checking out of bounce condition
        printf("Error No such index exists");
        return;
    }

    swap(arr,first,second); //call function and swapping
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]); //printin all the values
    }
}
