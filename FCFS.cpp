#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrival_time[n], burst_time[n], waiting_time[n], turn_around_time[n], completion_time[n];

    for (i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process" << i+1 <<":";
        cin >>arrival_time[i]>>burst_time[i];
    }

    // Sorting based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j]) {
                // Swap arrival time
                int temp = arrival_time[i];
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
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    for (i = 0; i < n; i++) {
        cout << i + 1 <<"\t\t " <<  arrival_time[i] <<"\t\t "<< burst_time[i]<<"\t\t "<< completion_time[i]<<"\t\t "<< turn_around_time[i]<<"\t\t "<< waiting_time[i] << endl;
    }

    return 0;
}