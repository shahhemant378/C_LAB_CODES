// Online C compiler to run C program online
#include <stdio.h>
void printEvenAtOdd(int* arr,int n){
    int i;
    for(i=1;i<n;i=i+2){
        if(*(arr+i)%2==0){
            printf("\nThe index at %d is %d\t",i,*(arr+i));
        }
}
}
int main() {
    // Create a function that prints all the even no present in odd indexes
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        printf("\nEnter %d index value:",i);
        scanf("%d",&arr[i]);
    }
    printEvenAtOdd(arr,n);
  return 0;
 
    }

  
