// Online C compiler to run C program online
#include <stdio.h>

void PRIME(int n){
    if(n<=1){
        printf("%d is not prime",n);
        return;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i!=0){
            printf("%d is Prime",n);
            return;
        }
    }
    printf("%d is not Prime",n);
}
int main() {
//Write a C program to determine whether a number is prime or not using a function named as "PRIME".
//Set 1: Enter an integer: 7 
//Set 1: 7 is prime

//Set 2: Enter an integer: 6 
//Set 2: 6 is not prime.
    int n=0;
   printf("Enter an integer: ");
   scanf("%d",&n);
   
  PRIME(n);

    return 0;
}
