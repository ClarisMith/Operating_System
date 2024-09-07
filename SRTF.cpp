#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], remaining_time[n];
    int waiting_time[n], turn_around_time[n], completion_time[n];
    int completed = 0, current_time = 0, min_index;

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    while (completed < n)
    {
        int min_remaining = INT_MAX;
        min_index = -1;

        for (i = 0; i < n; i++)
        {
            if (arrival_time[i] <= current_time && remaining_time[i] < min_remaining && remaining_time[i] > 0)
            {
                min_remaining = remaining_time[i];
                min_index = i;
            }
        }

        if (min_index != -1)
        {
            remaining_time[min_index]--;
            if (remaining_time[min_index] == 0)
            {
                completed++;
                completion_time[min_index] = current_time + 1;
                turn_around_time[min_index] = completion_time[min_index] - arrival_time[min_index];
                waiting_time[min_index] = turn_around_time[min_index] - burst_time[min_index];
            }
        }
        current_time++;
    }

    // Displaying the results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turn_around_time[i], waiting_time[i]);
    }

    return 0;
}