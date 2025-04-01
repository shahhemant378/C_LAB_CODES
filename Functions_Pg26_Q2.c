// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool checkSingleDigitOrNot(int n){
    int count=0;
    while(n>0){
        count++;
        n=n/10;
    }
    if(count==1) return true;
    return false;
}

int sumOfDigits(int n){
    int sum=0;
    while(n>0){
       int rem=n%10;
       sum=sum+rem;
       n=n/10;
    }
    return sum;
}
int main() {
 //WAP by designing a recursive function to calculate the sum of the digits of any given integer until it becomes a single digit number using function
 //Input:
 // Enter a number: 589
 //Output:
 // Sum of the digits (up t single digit) of 589 =4
 
 //Input: 
 //Enter a number: 25
 //Output;
 //Sum of the digits (up to single digit) of 25 =7
 int n=0;
 printf("Enter a number:");
 scanf("%d",&n);
 int dub=n;
    while(!checkSingleDigitOrNot(n)){
        n=sumOfDigits(n);
    }    
    printf("Sum of the digits (up ot  single digit) of %d = %d",dub,n);

    return 0;
}
