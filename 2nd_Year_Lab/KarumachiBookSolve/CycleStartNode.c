//Problem-11 Check whether the given linked list is NULL-terminated or not. If there is a cycle find the start node of the loop.  
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
  struct Node {
      int data;
      struct Node *next;
  };
 
struct Node *detectCycle(struct Node *head) {
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    struct Node *slow=head;
    struct Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
void main(){
    struct Node *head;
head=(struct Node*) malloc(sizeof(struct Node));
head->data=1;
head->next=(struct Node*)malloc(sizeof(struct Node));
head->next->data=2;
head->next->next=(struct Node*)malloc(sizeof(struct Node));
head->next->next->data=3;
head->next->next->next=head->next;
struct Node* Result=detectCycle(head);
if(Result==NULL) printf("Linked List is NULL-Terminated");
else printf("%d",Result->data);
}