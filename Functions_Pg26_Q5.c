// Online C compiler to run C program online
#include <stdio.h>

void palindromeOrNot(int n){
    int dub=n;
    int num=0;
    while(n>0){
        int rem=n%10;
        num=num*10 +rem;
        n=n/10;
    }
    if(num==dub){
        printf("Number is Palindrome");
    }else{
        printf("Number is not Palindrome");
    }
}
int main() {
//WAP to test whether a number n is palindrome number or not.
//Input:
// Enter a number to test for palindrome: 123
//Outpue:
// Entered nubmer: 123
//Number is not palindrome

//Input
//Enter a number to test for palindrome: 1551
//Output
// Entered number : 1551
//Number is palindrome
int n=0;
printf("Enter a number to test for palindrome: ");
scanf("%d",&n);
palindromeOrNot(n);

    return 0;
}
