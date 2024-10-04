#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int completed;
};

void calculateWaitingTime(struct Process processes[], int n) {
    int currentTime = 0;
    int completed = 0;

    while (completed != n) {
        int shortest = -1;
        int minBurstTime = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].completed) {
                if (processes[i].burstTime < minBurstTime) {
                    minBurstTime = processes[i].burstTime;
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            currentTime++;
            continue;
        }

        processes[shortest].waitingTime = currentTime - processes[shortest].arrivalTime;
        currentTime += processes[shortest].burstTime;
        processes[shortest].turnaroundTime = processes[shortest].waitingTime + processes[shortest].burstTime;
        processes[shortest].completed = 1;
        completed++;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

void displayGanttChart(struct Process processes[], int n) {
    printf("\nGantt Chart:\n");

    for (int i = 0; i < n; i++) {
        printf("  P%d  ", processes[i].pid);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("|     ");
    }
    printf("\n");

    int totalTime = 0;

    for (int i = 0; i < n; i++) {
        printf("%d      ", totalTime);
        totalTime += processes[i].burstTime;
    }
    printf("%d\n\n", totalTime);
}

void displayProcessTable(struct Process processes[], int n) {
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burstTime,
               processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        processes[i].completed = 0;
    }

    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    displayGanttChart(processes, n);
    displayProcessTable(processes, n);

    return 0;
}
