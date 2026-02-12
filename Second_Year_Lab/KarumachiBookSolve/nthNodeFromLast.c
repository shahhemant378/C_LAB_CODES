//2)find the nth node from the end of the Linked List.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node findNthNodeFromLast(int n,struct Node* HashTable,int *HTSize){
    if(*HTSize-n>=0 && *HTSize-n<*HTSize)
    return HashTable[*HTSize-n];
    
    struct Node result;
    result.data=-1;
    return result;
}
struct Node* makeHashTableofLL(struct Node *head,int *HTSize){
    struct Node *curr=head;
    struct Node* HT=(struct Node*) malloc(sizeof(struct Node));
    int i=0; 
    while(curr!=NULL){
        if(i>*HTSize-1){
            struct Node *new=realloc(HT,((*HTSize)+1) * sizeof(struct Node));
            HT=new;
            (*HTSize)++;
            
        }
        HT[i]=*curr;
        i++;
        curr=curr->next;
    }
    return HT;
}
void main(){
struct Node *head;
head=(struct Node*) malloc(sizeof(struct Node));
head->data=1;
head->next=(struct Node*)malloc(sizeof(struct Node));
head->next->data=2;
head->next->next=(struct Node*)malloc(sizeof(struct Node));
head->next->next->data=3;
head->next->next->next=NULL;
int HTSize=1;
struct Node nthNode=findNthNodeFromLast(1,makeHashTableofLL(head,&HTSize),&HTSize);
printf("%d",nthNode.data);
}