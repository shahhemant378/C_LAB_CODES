// WAP to add two numbers entered through the keyboard by using a suitable user defined function
// Set 1: Enter number 17 10  output:Sum of 17 and 10 = 27
// Set 2: Enter number: 5 -12 Output: Sum of 5 and -12 = -7
#include <stdio.h>
void add(){
    int a=0; int b=0;
    printf("Enter number a and b:- ");
    scanf("%d %d",&a,&b);
    
    printf("Sum of %d and %d is : %d ",a,b,a+b);
}
void main() {
    
    add();


}
