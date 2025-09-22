// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool isPerfectSquare(int n){
    int N=(int)sqrt(n);
    if((N*N)==n) return true;
    return false;
}
bool fiboOrNOt(int n){
    int check1=(5*n*n) -4;
    int check2=(5*n*n) +4;
    if(isPerfectSquare(check1)||isPerfectSquare(check2)){
        return true;
    }
    return false;
}
int main() {
    //WAP to test whether a number entered through the keyboard is a number in the Fibonacci sequence or not.(Using function)
    
    //Input:
    //Enter the number to test whether it is in Fibonacci sequence or not: 10
    //Output Entered number: 10
    //Number is in Fibonacci sequence : No;
    
    //Input :
    //Enter the number to test whether it is in Fibonacci sequence or not: 8
    //Output:
    //Enterd number:8
    //Number is in Fiboacci sequence : Yes
    int n=0;
    printf("Enter the number to test whether it is in Fibonacci sequence or not: ");
    scanf("%d",&n);
    if(fiboOrNOt(n)){
    printf("Number is in Fibonacci sequence : Yes");
    }else{
       printf("Number is in Fibonacci sequence:NO"); 
    }
    

    return 0;
}
