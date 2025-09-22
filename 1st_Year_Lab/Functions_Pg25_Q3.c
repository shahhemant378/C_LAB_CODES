// Online C compiler to run C program online
#include <stdio.h>

int fibonnaciNumber(int terms){
    if(terms==1) return 0;
    if(terms==2) return 1;
    int lastterm=0;
    int first=0;
    int second=1;
 for(int i=0;i<terms-2;i++){
     lastterm=second+first;
     first=second;
     second=lastterm;
 }
 return lastterm;
}
int main() {
/*A Fibonacci sequence is defined as follows: the first and second terms in thesequence are 0 and 1. Subsequent terms are found by adding the preceding two terms in the sequence (Fi = Fi-1 + Fi-2). WAP to find out the value of nth term of the Fibonacci sequence by writing a suitable user defined function.

Set 1:
Enter Fibonacci
term serial
number: 2

Set 1:
Fibonacci term serial
number: 2
Fibonacci number: 1

Set 2:
Enter Fibonacci
term serial
number: 8


Set 2:
Fibonacci term serial
number: 8
Fibonacci number: 13*/
    int terms=0;
   printf("Enter Fibonacci term serial number: ");
   scanf("%d",&terms);
   
   printf("Fibonacci number: %d",fibonnaciNumber(terms));

    return 0;
}
