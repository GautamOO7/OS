#include <stdio.h>

void calculateTimes(int n, int arrivalTime[], int burstTime[], int ATAT[], int AWT[]) {
    int completionTime[n], waitingTime[n], turnaroundTime[n];

    // Calculating completion time for each process
    completionTime[0] = burstTime[0];
    for (int i = 1; i < n; i++) {
        completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    // Calculating waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        AWT[0] += waitingTime[i];
        ATAT[0] += turnaroundTime[i];
    }

    // Calculating average waiting time and average turnaround time
    AWT[0] /= n;
    ATAT[0] /= n;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n], ATAT[1], AWT[1];
    ATAT[0] = 0;
    AWT[0] = 0;

    // Taking arrival time and burst time inputs from the user
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst time: ");
        scanf("%d", &burstTime[i]);
    }

    // Calculate ATAT and AWT
    calculateTimes(n, arrivalTime, burstTime, ATAT, AWT);

    // Displaying the results
    printf("Average Turnaround Time (ATAT): %d\n", ATAT[0]);
    printf("Average Waiting Time (AWT): %d\n", AWT[0]);

    return 0;
}
