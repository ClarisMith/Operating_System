#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, i, j;
    cout <<"Enter the number of processes: ";
    cin >>n;

    int arrival_time[n], burst_time[n], remaining_time[n];
    int waiting_time[n], turn_around_time[n], completion_time[n];
    int completed = 0, current_time = 0, min_index;

    for (i = 0; i < n; i++)
    {
        cout <<"Enter arrival time and burst time for process "<< i + 1 <<":";
        cin >>arrival_time[i] >>burst_time[i];
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
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    for (i = 0; i < n; i++) {
        cout << i + 1 <<" \t\t " <<  arrival_time[i] <<"\t\t "<< burst_time[i]<<"\t\t "<< completion_time[i]<<"\t\t "<< turn_around_time[i]<<"\t\t "<< waiting_time[i] << endl;
    }

    return 0;
}