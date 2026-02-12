#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int degree;
    struct Node* next;
};
struct Node* minimizeLL(struct Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node* traverse=head;
    while(traverse!=NULL){
        if(traverse->next!=NULL){
            if(traverse->degree==traverse->next->degree){
                traverse->coeff+=traverse->next->coeff;
                struct Node* temp=traverse->next;
                traverse->next=temp->next;
                free(temp);
            }else{
                traverse=traverse->next;
            }
        }else{
            traverse=traverse->next;
        }
    }
    return head;
}

void print(struct Node* head){
    struct Node* curr=head;
    while(curr!=NULL){
        printf("(%dx%d )->",curr->coeff,curr->degree);
        curr=curr->next;
    }
}
void main(){
  struct Node *head;
    head=(struct Node*) malloc(sizeof(struct Node));
    head->coeff=3;
    head->degree=2;

    head->next=(struct Node*) malloc(sizeof(struct Node));
    head->next->coeff=3;
    head->next->degree=3;

    head->next->next=NULL;

    head->next->next=(struct Node*) malloc(sizeof(struct Node));
    head->next->next->coeff=4;
    head->next->next->degree=2;

    head->next->next->next=(struct Node*) malloc(sizeof(struct Node));
    head->next->next->next->coeff=5;
    head->next->next->next->degree=0;

    head->next->next->next->next=(struct Node*) malloc(sizeof(struct Node));
    head->next->next->next->next->coeff=2;
    head->next->next->next->next->degree=0;



    head->next->next->next->next->next=NULL;

    head=minimizeLL(head);
    print(head);
}