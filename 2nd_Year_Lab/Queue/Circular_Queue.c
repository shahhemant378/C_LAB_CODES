#include<stdio.h>
#include<limits.h>

int Front=-1,Rear=-1;
void add(int* Q,int MaxSize,int x){
    if(Front==-1 && Rear==-1){
        Front=(Front+1)%MaxSize;
        Rear=(Rear+1)%MaxSize;
        Q[Rear]=x;
        printf("Added:%d\n",x);
        return;
    }
    int temp=(Rear+1)%MaxSize;

    //OVERFLOW KA CONDITION
    if(Front==temp){
        printf("Overflow\n");
        return;
    }
    Rear=temp;
    Q[Rear]=x;
    printf("Added: %d\n",x);
}
int delete(int *Q,int MaxSize){
    int value=Q[Front];

    //UNDERFLOW KA CONDITION
    if(Front==-1){
         printf("Underflow\n");
       return INT_MIN;
    }

    //RESETTING THE REAR AND REAR TO -1
    if(Front==Rear){
        Front=-1;
        Rear=-1;
        printf("Deleted :%d\n",value);
       
        return INT_MIN;
    }
    Front=(Front+1)%MaxSize;
    printf("Deleted: %d\n",value);
    return value;
}
void print(int *Q,int MaxSize){
    int i;
    for(i=0;i<MaxSize;i++){
        printf("%d ",Q[i]);
    }
}
void main(){
int Q[3];
int MaxSize=3;
add(Q,MaxSize,5);
add(Q,MaxSize,9);
add(Q,MaxSize,5);
add(Q,MaxSize,9);
delete(Q,MaxSize);
delete(Q,MaxSize);
delete(Q,MaxSize);
delete(Q,MaxSize);
add(Q,MaxSize,8);
add(Q,MaxSize,8);
delete(Q,MaxSize);
delete(Q,MaxSize);
delete(Q,MaxSize);
delete(Q,MaxSize);
print(Q,MaxSize);
delete(Q,MaxSize);
delete(Q,MaxSize);
add(Q,MaxSize,8);
printf("Front: %d",Front);
printf("Rear: %d",Rear);


}