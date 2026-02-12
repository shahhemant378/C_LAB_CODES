#include <stdio.h>
#include <stdlib.h>

struct Node{
    int a;
    struct Node *next;
};

void main(){
    struct Node *head,*new,*current;
    current=(struct Node*)malloc(sizeof(struct Node));
  
    current->a=20;
    current->next=NULL;
     head=current;

     current->next=(struct Node*)malloc(sizeof(struct Node));
     current->next->a=40;
     current->next->next=NULL;
     

     int count=0;
     while(head->next!=NULL){
        count++;
        head=head->next;
     }
     printf("%d",count);
     
}