//Find the greater number 
// a
// b

// call by reference

#include <stdio.h>

int greaterNumber(int *A,int *B){
    if(*A>*B){
        return *A;
    }else{
        return *B;
    }
}
void main(){
int a,b;
scanf("%d %d",&a,&b);
int G=greaterNumber(&a,&b);

printf("The Greater Element: %d",G);

}