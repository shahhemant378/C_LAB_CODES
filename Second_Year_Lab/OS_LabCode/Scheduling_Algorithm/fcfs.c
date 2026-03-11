#include <stdio.h>
#include <stdlib.h>

struct Node{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};

int compareAT(const void *a,const void *b){
    return ((struct Node*)a)->at - ((struct Node*)b)->at;
}

int comparePID(const void *a,const void *b){
    return ((struct Node*)a)->pid - ((struct Node*)b)->pid;
}

int main(){

    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Node p[n];

    for(int i=0;i<n;i++){
        printf("Enter PID AT BT: ");
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
    }

    // sort by arrival time
    qsort(p,n,sizeof(struct Node),compareAT);

    struct Node* queue[100];
    int front=0,rear=-1;

    int completed=0;
    int i=0;
    struct Node *curr;

    while(front<=rear || i<n){

        if(front<=rear){
            curr = queue[front++];
        }else{
            curr = &p[i++];
        }

        completed += curr->bt;

        curr->ct = completed;
        curr->tat = curr->ct - curr->at;
        curr->wt = curr->tat - curr->bt;
        curr->rt = curr->wt;

        while(i<n && p[i].at < completed){
            queue[++rear] = &p[i];
            i++;
        }
    }

    // sort back by PID
    qsort(p,n,sizeof(struct Node),comparePID);

    printf("\nPID AT BT CT TAT WT RT\n");

    for(int j=0;j<n;j++){
        printf("%d %d %d %d %d %d %d\n",
        p[j].pid,p[j].at,p[j].bt,p[j].ct,p[j].tat,p[j].wt,p[j].rt);
    }

    return 0;
}