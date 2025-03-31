#include <stdio.h>

int fact(int n){
    if(n==0)return 1;
    if(n==1) return 1;
    int i;
    int fact=1;
    for(i=2;i<=n;i++){
        fact=fact*i;
    }
    
    return fact;
}
int main() {
    // WAP to find the factorial of a number n by using a suitable user defined function. 
    //Set 1:Enter a number: 5 
    //Set 1:Factorial of 5 = 120 
    //Set 2: Enter a number: 0 
    //Set 2: Factorial of 0 = 1
    int n=0;
    printf("Enter the number");
    scanf("%d",&n);
    printf("Factorial of %d = %d",n,fact(n));

    return 0;
}
