#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], priority[n],   
 waiting_time[n], turn_around_time[n], completion_time[n];

    for (i = 0; i < n; i++) {
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &arrival_time[i], &burst_time[i], &priority[i]);   

    }

    // Sorting based on priority (higher priority goes first)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] < priority[j]) {
                // Swap priority
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap arrival time
                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                // Swap burst time
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;   

            }
        }
    }

    // Calculating completion time
    completion_time[0] = arrival_time[0] + burst_time[0];
    for (i = 1; i < n; i++) {
        if (arrival_time[i] > completion_time[i - 1]) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            completion_time[i] = completion_time[i - 1] + burst_time[i];   

        }
    }

    // Calculating turn around time and waiting time
    for (i = 0; i < n; i++) {
        turn_around_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turn_around_time[i] - burst_time[i];
    }

    // Displaying the results
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",   
 i + 1, arrival_time[i], burst_time[i], priority[i], completion_time[i], turn_around_time[i], waiting_time[i]);
    }

    return 0;
}