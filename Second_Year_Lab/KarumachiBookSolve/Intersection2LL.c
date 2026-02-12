/*Problem-17 Suppose there are two singly linked lists both of which intersect at some point
and become a single linked list. The head or start pointers of both the lists are known, but
the intersecting node is not known. Also, the number of nodes in each of the lists before
they intersect is unknown and may be different in each list. List1 may have n nodes before
it reaches the intersection point, and List2 might have m nodes before it reaches the
intersection point where m and n may be m = n,m < n or m > n. Give an algorithm for
finding the merging point.*/

#include<stdio.h>
#include<stdlib.h>
  struct Node {
      int data;
      struct Node *next;
 };

struct Node *getIntersectionNode(struct Node *headA, struct Node *headB) {
    if(headA==NULL || headB==NULL){
        return NULL;
    }
    int countA=0,countB=0;
    struct Node *currA=headA,*currB=headB;

    while(currA!=NULL || currB!=NULL){
        if(currA!=NULL){
            countA++;
            currA=currA->next;
        }
        if(currB!=NULL){
            countB++;
            currB=currB->next;
        }
    }
    currB=headB;
    currA=headA;
    if(countA>countB){
        int i; 
        
        for(i=0;i<countA-countB;i++){
            currA=currA->next;
        }

    }else{
        int i;
        
        for(i=0;i<countB-countA;i++){
            currB=currB->next;
        }
    }
    while(currA!=NULL && currB!=NULL){
        if(currA==currB)return currA;
        currA=currA->next;
        currB=currB->next;
        
    }
    return NULL;
}

// Helper function to create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void main() {
    // Create intersection part: 7 -> 6 -> NULL
    struct Node* intersect = newNode(7);
    intersect->next = newNode(6);

    // Create List A: 1 -> 2 -> 3 -> 7 -> 6
    struct Node* headA = newNode(1);
    headA->next = newNode(2);
    headA->next->next = newNode(3);
    headA->next->next->next = intersect;

    // Create List B: 9 -> 8 -> 7 -> 6
    struct Node* headB = newNode(9);
    headB->next = newNode(8);
    headB->next->next = intersect;

    // Find intersection
    struct Node* result = getIntersectionNode(headA, headB);

    if(result != NULL) {
        printf("Intersection at node with value: %d\n", result->data);
    } else {
        printf("No intersection found.\n");
    }


}