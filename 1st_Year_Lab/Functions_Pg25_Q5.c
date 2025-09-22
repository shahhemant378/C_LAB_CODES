// Online C compiler to run C program online
#include <stdio.h>
void SWAP(int *pa,int *pb){
    int temp=*pa;
    *pa=*pb;
    *pb=temp;
}
int main() {
    // WAP to perform swapping of two integers using a function SWAP
    //Set 1: Enter num1=10 
           //Enter num2=20
           
    //Set 1: Before Swapping 
    //  num1=10
    // num2=20
    
    // After Swapping
    //num1=20
    //num2=10
    int a=10;
    int b=20;
    
    //Before Swapping
    printf("Before Swapping\n");
    printf("num 1 = %d\n",a);
    printf("num 2= %d ",b);
    SWAP(&a,&b);
    
    printf("\n");
    //After Swapping
    printf("After Swapping\n");
    printf("num 1 = %d\n",a);
    printf("num 2 = %d",b);
    

    

    return 0;
}
