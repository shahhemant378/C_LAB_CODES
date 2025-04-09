// Online C compiler to run C program online
#include <stdio.h>
void add(int a,int b){
    printf("The sum of %d and %d is %d",a,b,a+b);
}
void sub(int a ,int b){
    printf("The subtraction of %d and %d is %d",a,b,a-b);
}

void mul(int a,int b){
    int i;
    int sum=0;
    for(i=0;i<b;i++){
        sum+=a;
    }
    printf("The multiplication of %d and %d is %d",a,b,sum);
}
void div(int a,int b){
    int count=0;
    int sum=0;
    if(a<b){
        printf("The division of %d and %d is %d",a,b,0);
    }else{
    while(sum<=a){
        sum+=b;
        count++;
    }
    }
    printf("The division of %d and %d is %d",a,b,count);
}
void mudulo(int a ,int b){
    int sum=a;
    int i=0;
    for(i=0;i<div(a,b);i++){
        sum-=b;
    }
    printf("The mudulos of %d and %d is %d",a,b,sum);
}
 
int main() {
    // Write C code here
printf("What do you want to do ? \n 1) Addition \n 2) Subtraction \n 3) Multiplication \n 4) Division \n 5) Mudulos\n ");
printf("Enter your choice:");
int n=0;
int a=0;
int b=0;
scanf("%d",&n);
printf("Enter two number:");
scanf("%d%d",&a,&b);
switch(n){
    case 1:
    void add(a,b);
    break;
    case 2:
    void sub(a,b);
    break;
    case 3:
    void mul(a,b);
    break;
    case 4:
    void div(a,b);
    break;
    case 5:
    void mudulo(a,b);
    break;
    default:
    printf("You have entered wrong number or not entered and number");
}
    return 0;
}
