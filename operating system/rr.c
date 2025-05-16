#include <stdio.h>
int n=5;

void fcfs(int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n];
    int total_wt = 0, total_tat = 0;
    int completion_time[n];

    // Completion time for first process = burst time
    completion_time[0] = burst_time[0];
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i];  // AT=0 for all processes
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nFCFS Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

void round_robin(int n, int burst_time[], int time_quantum) {
    int rem_bt[n];
    int waiting_time[n], turnaround_time[n];
    int t = 0; // Current time
    int done = 0;

    for (int i = 0; i < n; i++) {
        rem_bt[i] = burst_time[i];
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }

    while (done < n) {
        done = 0;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                if (rem_bt[i] > time_quantum) {
                    t += time_quantum;
                    rem_bt[i] -= time_quantum;
                } else {
                    t += rem_bt[i];
                    waiting_time[i] = t - burst_time[i];
                    rem_bt[i] = 0;
                }
            }
            if (rem_bt[i] == 0)
                done++;
        }
    }

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nRound Robin Scheduling (Time Quantum = %d):\n", time_quantum);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int  time_quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    fcfs(n, burst_time);
    round_robin(n, burst_time, time_quantum);

    return 0;
}
