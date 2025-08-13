 #include <stdio.h>
 #include <stdlib.h>


struct Node {
      int data;
      struct Node* next;
  };
 
 

struct Node* insertNodeAtPosition(struct Node* head, int data, int position) {
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
struct Node *temp=head;
if(position==0){
    newNode->next=head;
    head=newNode;
}
int i=0;
while(i<=position){
    if(i==position-1){
      struct Node* temporary=temp->next;
      temp->next=newNode;
      newNode->next=temporary;  
    }
    temp=temp->next;
    i++;
}
return head;
}

struct Node* delete(struct Node* head,int pos,int Lidx){
    if(head==NULL || pos>Lidx || pos<0){ // base cases 
        return head;
    }
    if(pos==0){ //condition if i want to delete head node
        struct Node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int i=0;
    struct Node* temporary=head; //storing head to the temporary for future purposes
    while(i<=pos-2){// reaching to the just before position of the node which i want to delete
        temporary=temporary->next;
        i++;
    }
    struct Node* todelete=temporary->next;
    if(todelete==NULL) return head;
    temporary->next=todelete->next;
    free(todelete);
    // int i=0;
    // if(position==0){
    //     struct Node *t=head;
    //     head=head->next;
    //     free(t);
    //     return head;
    // }
    // struct Node* temp=head;
    // while(i<=position-1){
    //     temp=temp->next;
    //     i++;
    // }
    // struct Node* temporary=temp->next;
    // temp->next=temporary->next;
    // free (temporary);
    return head;
}
void print(struct Node* head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
}
int sizeIntermsOfIndex(struct Node* head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
void main(){
    struct Node *head;
    head=(struct Node*) malloc(sizeof(struct Node));
    head->data=1;
    head->next=(struct Node*) malloc(sizeof(struct Node));
    head->next->data=2;
    head->next->next=(struct Node*) malloc(sizeof(struct Node));
    head->next->next->data=3;
    head->next->next->next=NULL;
    printf("Which position you want to delete: ");
    int pos;
    scanf("%d",&pos);

    // printf("Enter the data you want to add: ");
    // int data;
    // scanf("%d",&data);
    // insertNodeAtPosition(head, data, pos);
  
    head=delete(head,pos,sizeIntermsOfIndex(head));
    print(head);


}