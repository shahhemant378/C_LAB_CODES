#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
} Process;

Process heap[MAX];
int heapSize = 0;

// -------------------- Heap Functions --------------------

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Min heap based on Burst Time
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].bt > heap[index].bt) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left].bt < heap[smallest].bt)
        smallest = left;

    if (right < heapSize && heap[right].bt < heap[smallest].bt)
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insertHeap(Process p) {
    heap[heapSize] = p;
    heapifyUp(heapSize);
    heapSize++;
}

Process extractMin() {
    Process min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return min;
}

// -------------------- Sorting by Arrival Time --------------------

int compareAT(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->at - p2->at;
}

// -------------------- Main --------------------

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID AT BT: ");
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
    }

    // Step 1: Sort by Arrival Time
    qsort(p, n, sizeof(Process), compareAT);

    int currentTime = 0;
    int completed = 0;
    int i = 0;

    while (completed < n) {

        // Insert all arrived processes into heap
        while (i < n && p[i].at <= currentTime) {
            insertHeap(p[i]);
            i++;
        }

        if (heapSize == 0) {
            currentTime = p[i].at;
            continue;
        }

        // Select shortest job
        Process chosen = extractMin();

        currentTime += chosen.bt;

        chosen.ct = currentTime;
        chosen.tat = chosen.ct - chosen.at;
        chosen.wt = chosen.tat - chosen.bt;
        chosen.rt = chosen.wt;

        printf("PID: %d AT: %d BT: %d CT: %d TAT: %d WT: %d RT: %d\n",
               chosen.pid, chosen.at, chosen.bt,
               chosen.ct, chosen.tat, chosen.wt, chosen.rt);

        completed++;
    }

    return 0;
}