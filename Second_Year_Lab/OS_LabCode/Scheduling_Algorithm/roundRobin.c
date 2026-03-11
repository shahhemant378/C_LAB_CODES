#include <stdio.h>
#include <stdlib.h>

struct Node{
    int p_id;
    int at;
    int bt;
    int Gcom;
    int tat;
    int wt;
    int rt;
    int dbt;
    int intime;
};

void sortByArrival(struct Node p[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].at > p[j].at){
                struct Node temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void sortByPID(struct Node p[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].p_id > p[j].p_id){
                struct Node temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main(){

    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Node p[n];

    for(int i=0;i<n;i++){
        printf("Enter PID AT BT: ");
        scanf("%d %d %d",&p[i].p_id,&p[i].at,&p[i].bt);

        p[i].dbt = p[i].bt;
        p[i].intime = -1;
        p[i].Gcom = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        p[i].rt = 0;
    }

    int qt;
    printf("Enter quantum time: ");
    scanf("%d",&qt);

    sortByArrival(p,n);

    int q[100];
    int front=0,rear=0;

    int completed=0;
    int i=0;
    int currIndex;

    while(front!=rear || i<n){

        if(front!=rear){
            currIndex = q[front];
            front++;
        }
        else{
            currIndex = i;
            i++;
            if(completed < p[currIndex].at)
                completed = p[currIndex].at;
        }

        if(p[currIndex].intime==-1)
            p[currIndex].intime = completed;

        int exec;

        if(p[currIndex].dbt >= qt)
            exec = qt;
        else
            exec = p[currIndex].dbt;

        p[currIndex].dbt -= exec;
        completed += exec;

        p[currIndex].Gcom = completed;
        p[currIndex].tat = p[currIndex].Gcom - p[currIndex].at;
        p[currIndex].wt = p[currIndex].tat - p[currIndex].bt;
        p[currIndex].rt = p[currIndex].intime - p[currIndex].at;

        while(i<n && p[i].at<=completed){
            q[rear] = i;
            rear++;
            i++;
        }

        if(p[currIndex].dbt > 0){
            q[rear] = currIndex;
            rear++;
        }
    }

    sortByPID(p,n);

    for(int j=0;j<n;j++){
        printf("PID: %d AT: %d BT: %d CT: %d TAT: %d WT: %d RT: %d\n",
        p[j].p_id,
        p[j].at,
        p[j].bt,
        p[j].Gcom,
        p[j].tat,
        p[j].wt,
        p[j].rt);
    }

    return 0;
}