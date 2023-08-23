#include <stdio.h>

void calculateTimes(int n, int arrivalTime[], int burstTime[], int ATAT[], int AWT[]) {
    int completionTime[n], remainingTime[n];
    int smallest, currentTime = 0, processCount = 0;

    // Initializing remaining time array
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    while (processCount != n) {
        smallest = -1;

        // Find the process with the smallest remaining burst time
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] > 0) {
                if (smallest == -1 || remainingTime[i] < remainingTime[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            currentTime++;
        } else {
            // Process found with smallest burst time
            completionTime[smallest] = currentTime + burstTime[smallest];
            currentTime += burstTime[smallest];
            remainingTime[smallest] = 0;
            processCount++;

            // Calculating waiting time and turnaround time for the process
            AWT[0] += currentTime - arrivalTime[smallest] - burstTime[smallest];
            ATAT[0] += currentTime - arrivalTime[smallest];
        }
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
