#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int pid, at, bt, remaining;
    int ct, tat, wt, rt;
    int started;
} Process;

int compareAT(const void *a, const void *b) {
    return ((Process *)a)->at - ((Process *)b)->at;
}

int main() {

    int n, qt;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Quantum time: ");
    scanf("%d", &qt);

    Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID AT BT: ");
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
        p[i].remaining = p[i].bt;
        p[i].started = 0;
    }

    qsort(p, n, sizeof(Process), compareAT);

    int queue[MAX];
    int front = 0, rear = 0;

    int currentTime = 0;
    int i = 0, completed = 0;

    while (completed < n) {

        while (i < n && p[i].at <= currentTime)
            queue[rear++] = i++;

        if (front == rear) {
            currentTime = p[i].at;
            continue;
        }

        int idx = queue[front++];
        Process *curr = &p[idx];

        if (!curr->started) {
            curr->rt = currentTime - curr->at;
            curr->started = 1;
        }

        int runTime = (curr->remaining < qt) ? curr->remaining : qt;

        currentTime += runTime;
        curr->remaining -= runTime;

        while (i < n && p[i].at <= currentTime)
            queue[rear++] = i++;

        if (curr->remaining > 0)
            queue[rear++] = idx;
        else {
            curr->ct = currentTime;
            curr->tat = curr->ct - curr->at;
            curr->wt = curr->tat - curr->bt;
            completed++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("PID: %d AT: %d BT: %d CT: %d TAT: %d WT: %d RT: %d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    return 0;
}