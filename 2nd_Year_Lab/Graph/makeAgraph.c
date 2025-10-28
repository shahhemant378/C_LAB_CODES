#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>


struct QNode{ // making a Node
    int val;
    struct QNode *next;

};
struct Queue{ // making  a queue
 struct QNode *front;
 struct QNode *rear;
};

//create the new queue
struct Queue* queueCreate(){
    struct Queue* Q=(struct Queue*) malloc(sizeof(struct Queue));
    Q->front=Q->rear=NULL;
    return Q;
}
//add in a queue
void push(int val,struct Queue* Q){
    struct QNode* newNode=(struct QNode*)malloc(sizeof(struct QNode));
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
        
    struct QNode *del=Q->front;
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

//--------------------------------




//make a listNode
struct Node{
    int val;
    struct Node *next;
};
//make a adjency List
void makeAdjacencyList(struct Node* graph[],int v,int src,int dest){
    if(src<0 || src>v || dest<0 || dest>v)
        return;
    //newNode creation of dest which will be added to src->dest
    struct Node* newNodedest=(struct Node*)malloc(sizeof(struct Node));
    newNodedest->val=dest;
    newNodedest->next=NULL;

    if(graph[src]==NULL){
        graph[src]=newNodedest;
    }else{
        struct Node* temp=graph[src];
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newNodedest;
    }


    //create node for src (to attach to dest)
    struct Node* newNodeSrc=(struct Node*)malloc(sizeof(struct Node));
    newNodeSrc->val=src;
    newNodeSrc->next=NULL;

    if(graph[dest]==NULL){ //if there is no node present then adding in it
        graph[dest]=newNodeSrc;
    }else{
        struct Node *temp=graph[dest]; // if already present then adding at last
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNodeSrc;
    }

        
    }

void print(struct Node* graph[],int v){
    for(int i=0;i<v;i++){
        printf("%d = ",i);
        struct Node* List=graph[i];
        while(List!=NULL){
            printf("%d -> ",List->val);
            List=List->next;
        }
       // free(List);
        printf("\n");
    }
}

//dfs code
void dfs(struct Node* graph[],bool vis[],int curr){
    //just after coming make curr node visited suddenly
    vis[curr]=true;
    printf("%d -> ",curr);
    //find go to neighbours

    struct Node* neigh=graph[curr];
    while(neigh!=NULL){ //neigh should be not null
        if(!vis[neigh->val]) // neigh should be unvisited then only we can go 
        dfs(graph,vis,neigh->val);
        neigh=neigh->next;
    }
}

//bfs
void bfs(struct Node* graph[],bool vis[],int start){
    struct Queue* Q = queueCreate();
    push(start, Q);
    vis[start] = true;

    while (!isEmpty(Q)) {
        int curr = pop(Q);
        printf("%d -> ", curr);

        struct Node* neigh = graph[curr];
        while (neigh != NULL) {
            if (!vis[neigh->val]) {
                vis[neigh->val] = true;  // mark visited immediately
                push(neigh->val, Q);
            }
            neigh = neigh->next;
        }
    }

    freeQueue(Q);

}
void main(){
//make a Graph
int v=6; //number of nodes in graph
//make a graph

struct Node* graph[v];
for(int i=0;i<v;i++){
    graph[i]=NULL;
}
bool vis[v];


     makeAdjacencyList(graph, v, 0, 1);
    makeAdjacencyList(graph, v, 0,5);
    makeAdjacencyList(graph, v, 1, 2);
    makeAdjacencyList(graph, v, 1, 3);
    makeAdjacencyList(graph, v, 1, 4);
    makeAdjacencyList(graph, v, 2, 3);
    makeAdjacencyList(graph, v, 3, 4);

   // dfs(graph,vis,0);
    bfs(graph,vis,0);
     // print(graph,v);
}