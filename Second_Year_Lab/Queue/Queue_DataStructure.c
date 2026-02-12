// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{ // making a Node
    int val;
    struct Node *next;

};
struct Queue{ // making  a queue
 struct Node *front;
 struct Node *rear;
};

//create the new queue
struct Queue* queueCreate(){
    struct Queue* Q=(struct Queue*) malloc(sizeof(struct Queue));
    Q->front=Q->rear=NULL;
    return Q;
}
//add in a queue
void push(int val,struct Queue* Q){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->next=NULL;
    if(Q->rear==NULL){
        Q->front=Q->rear=newNode;
        return;
    }
        Q->rear->next=newNode;
        Q->rear=newNode;
    
}

//delete the front element
int pop(struct Queue* Q){
    if(Q->front==NULL)
        return -1;
        
    struct Node *del=Q->front;
    int temp=del->val;
    Q->front=Q->front->next;
    free(del);

    if(Q->front==NULL){
        Q->rear=NULL;
    }
    return temp;
}
//get the front value
int peek(struct Queue* Q){
     if(Q->front==NULL)
        return -1;
    return Q->front->val;
}
//queue is empty or not
bool isEmpty(struct Queue* Q){
    if(Q->front==NULL) return true;

    return false;
}

void freeQueue(struct Queue* Q){
    while(!isEmpty(Q)){
        pop(Q);
    }
    free(Q);
}



int main() {
    
    //Create Queue
    struct Queue *Q=queueCreate();
    push(1,Q);
    push(4,Q);
    push(8,Q);
    
    printf("%d",pop(Q));
    printf("%d",pop(Q));
    //  printf("%d",pop(Q));
    // printf("%d",pop(Q));

    if(isEmpty(Q))
        printf("yes");
    else
        printf("false");

    
    

    return 0;
}