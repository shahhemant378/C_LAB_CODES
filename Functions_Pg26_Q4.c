// Online C compiler to run C program online
#include <stdio.h>

int countingZeros(int n){
    int count=0;
    while(n>0){
        int rem=n%10;
        if(rem==0) count++;
        n=n/10;
    }
    return count;
}
int main() {
//Write a function that will return the counting of Zeros in a Positive Integer

//Input:
//Input:110560
//Outpue:
//No of zeros: 2

//Input:
//Input: 178655
//Output
//No of zeros: 0
int n=0;
printf("Input : ");
scanf("%d",&n);
printf("No of zeros: %d",countingZeros(n));

    return 0;
}
