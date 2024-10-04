#include <stdio.h>


typedef struct
{
    int process_id;
    int arrival_time;
    int burst_time;
} Process;

// Function to calculate waiting time and turnaround time for each process
void calculateWaitingTime(Process processes[], int n, int waiting_time[], int turnaround_time[])
{
    int completion_time[n];

    // Calculate completion time of first process
    completion_time[0] = processes[0].burst_time;

    // Calculate completion time of remaining processes
    for (int i = 1; i < n; i++)
    {
        completion_time[i] = completion_time[i - 1] + processes[i].burst_time;
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        waiting_time[i] = completion_time[i] - processes[i].arrival_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
}

// Function to calculate average waiting time and turnaround time
void calculateAverageTime(Process processes[], int n)
{
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;

    calculateWaitingTime(processes, n, waiting_time, turnaround_time);

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    printf("-----------------------------------------------------\n");
    printf("| Process | Arrival Time | Burst Time | Completion Time |\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("|   %d\t|      %d\t  |     %d\t|        %d\t    |\n",
            processes[i].arrival_time, processes[i].burst_time,
               processes[i].arrival_time + turnaround_time[i]);
    }

    printf("-----------------------------------------------------\n");

    // Calculate total waiting time and turnaround time
    for (int i = 0; i < n; i++)
    {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculate average waiting time and turnaround time
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}

int main()
{
    int n; // number of processes
    printf("Enter the number of process: ");
    scanf("%d", &n);

    Process processes[n];

    // Input process details
    printf("Arrival Time: ");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &processes[i].arrival_time);

    }
    printf("Burst Time: ");
    for (int i = 0; i < n; i++)
    {


        scanf("%d", &processes[i].burst_time);
    }

    calculateAverageTime(processes, n);

    return 0;
}
