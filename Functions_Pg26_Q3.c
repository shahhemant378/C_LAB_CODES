// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool PRIME(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main() {
//WAP to print all prime numbers between 1 to 100 using function
//Prime numbers between 1 to 100:
//2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

for(int i=1;i<=100; i++){
    if(PRIME(i)) printf("%d ",i);
}

    return 0;
}
