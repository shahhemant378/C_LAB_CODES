//Problem-6 Check whether the given linked list is either NULL-terminated or ends in a cycle (cyclic).
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node {
     int data;
     struct Node *next;
  };
 
bool hasCycle(struct Node *head) {
    if(head==NULL || head->next==NULL){
        return false;
    }
    struct Node *slow=head;
    struct Node *fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
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
if(hasCycle(head)) printf("Cycle");
else printf("No Cycle");
}