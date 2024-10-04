#include <stdio.h>

struct Process {
    int pid;      // Process ID
    int burst;    // Burst time
    int arrival;  // Arrival time
    int start;    // Start time
    int end;      // End time
};

void printGanttChart(struct Process processes[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d   ", processes[i].start);
    }
    printf("%d\n", processes[n - 1].end);
}

void preemptiveSTRN(struct Process processes[], int n) {
    int remaining[n];
    for (int i = 0; i < n; i++) {
        remaining[i] = processes[i].burst;
    }

    int currentTime = 0;
    int completed = 0;
    while (completed != n) {
        int shortestJob = -1;
        int shortestBurst = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= currentTime && remaining[i] < shortestBurst && remaining[i] > 0) {
                shortestJob = i;
                shortestBurst = remaining[i];
            }
        }

        if (shortestJob == -1) {
            currentTime++;
        } else {
            processes[shortestJob].start = currentTime;
            currentTime += 1;
            remaining[shortestJob] -= 1;

            if (remaining[shortestJob] == 0) {
                processes[shortestJob].end = currentTime;
                completed++;
            }
        }
    }

    printGanttChart(processes, n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("\nEnter burst time and arrival time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process P%d\n", processes[i].pid);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival);
    }

    preemptiveSTRN(processes, n);

    return 0;
    }
