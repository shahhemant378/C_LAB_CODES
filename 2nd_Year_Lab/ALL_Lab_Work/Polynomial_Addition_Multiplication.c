#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
struct poly{
    int coeff;
    int degree;
};
struct ans{
    struct poly *s;
    int size;
};
struct poly insertInStructure(){
    struct poly s;
    printf("Enter coefficient & degree");
    scanf("%d %d",&s.coeff,&s.degree);
    return s;
}

int* addPoly(struct poly poly1[],int size1, struct poly poly2[],int size2,int *finalSize){
    int i;
    int max=INT_MIN;
    for(i=0;i<size1;i++){
        if(poly1[i].degree>max){
            max=poly1[i].degree;
        }
    }
     for(i=0;i<size2;i++){
        if(poly2[i].degree>max){
            max=poly2[i].degree;
        }
    }
    *finalSize=max+1;
    int *additionResult=(int*) calloc(*finalSize,sizeof(int));

    for(i=0;i<size1;i++){
        int index=poly1[i].degree;
        additionResult[index]+=poly1[i].coeff;
    }
     for(i=0;i<size2;i++){
        int index=poly2[i].degree;
        additionResult[index]+=poly2[i].coeff;
    }

    return additionResult;


}

int* multiply(struct poly *poly1,int size1,struct poly *poly2,int size2,int *finalSize){
     int m=INT_MIN;
     int n=INT_MIN;
     int i,j;
    for(i=0;i<size1;i++){
        if(poly1[i].degree>m){
            m=poly1[i].degree;
        }
    }
     for(i=0;i<size2;i++){
        if(poly2[i].degree>n){
            n=poly2[i].degree;
        }
    }
    *finalSize=m+n+1;

    int *multipyResult=(int*) calloc(*finalSize,sizeof(int));

    for(i=0;i<size1;i++){
        for(j=0;j<size2;j++){
            int deg=poly1[i].degree + poly2[j].degree;
            multipyResult[deg]+=poly1[i].coeff * poly2[j].coeff;

        }
    }
    return multipyResult;
}
bool isfull(struct poly *arr,int *count,int curr){
if(*count<curr){
    return true;
}
return false;
}
struct poly* addMore(struct poly *arr,int newSize,int *count){
    *count=newSize-1;
return (struct poly*) realloc(arr,newSize*sizeof(struct poly));

}

struct ans insertPoly(){
    struct poly *arr;
    arr=(struct poly*) calloc(1,sizeof(struct poly));
    printf("Enter the polynomial and enter -1 to stop :\n");
    printf("-----------------------------------------------");
    bool condition=true;
    int i=0;
    int count=0;
 
    while(condition){

         if(isfull(arr,&count,i)){
            arr=addMore(arr,count+2,&count);
            printf("Enter coeff and degree: ");
               struct poly temp;
                scanf("%d",&temp.coeff);
                scanf("%d",&temp.degree);
                arr[i]=temp;
         }
            else{
                printf("\n");
                 printf("Enter coeff and degree: ");
                struct poly temp;
                scanf("%d",&temp.coeff);
                scanf("%d",&temp.degree);
                arr[i]=temp;
            }
            i++;

         printf("\n\n.......Stop -1 , continue (any number)...... ");
         int ask;
         scanf("%d",&ask);
         if(ask==-1){
            condition=false;
         }
    }
    struct ans Ans;
    Ans.s=arr;
    Ans.size=count+1;
return Ans;
}
void main(){
//add poly 1
struct ans Ans1=insertPoly();
//add poly 2
struct ans Ans2=insertPoly();

//addition of poly1 and poly2

printf("\nThe addition of 2 polynomial: \n");
int finalSize;
int *result=addPoly(Ans1.s,Ans1.size, Ans2.s,Ans2.size,&finalSize);
int i=0;
for(i=0;i<finalSize;i++){
    if(result[i]!=0)
    printf("%d x^%d \t",result[i],i);
}


printf("\n\nThe multiplication of 2  polynomial:\n");
 result=multiply(Ans1.s,Ans1.size,Ans2.s,Ans2.size,&finalSize);
for(i=0;i<finalSize;i++){
    if(result[i]!=0)
    printf("%d x^%d \t",result[i],i);
}
free(result);
//result
}