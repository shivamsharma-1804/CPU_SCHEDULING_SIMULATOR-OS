#include <stdio.h>
#include<unistd.h>
struct DiskRequest {
    int request_number; // Request number
    int priority;       // Priority for the request
};

void priorityDiskScheduling(int n, struct DiskRequest requests[], int wt[], int tat[]) {
     for (int i = 0; i < n; i++) {
        requests[i].request_number = i + 1;
        printf("Enter the priority for request %d: ", i + 1);
        scanf("%d", &requests[i].priority);
    }

    // Sort the requests based on priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requests[i].priority > requests[j].priority) {
                // Swap requests[i] and requests[j]
                struct DiskRequest temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + 1; // Assuming 1 unit time for each request
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + 1; // Assuming 1 unit time for each request
    }
}

// Function to calculate waiting time and turnaround time for FCFS
void fcfs(int n, int bt[], int wt[], int tat[]) {
    wt[0] = 0;
    tat[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }
}

// Function to calculate waiting time and turnaround time for SJF
void sjf(int n, int bt[], int wt[], int tat[]) {
    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[i] = bt[i];
    }

    for (int i = 0; i < n; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (temp[j] < temp[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the current element
        int tempValue = temp[i];
        temp[i] = temp[minIndex];
        temp[minIndex] = tempValue;

        int tempBurst = bt[i];
        bt[i] = bt[minIndex];
        bt[minIndex] = tempBurst;
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }
}

// Function to calculate waiting time and turnaround time for RR
void rr(int n, int bt[], int wt[], int tat[], int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = bt[i];
    }

    int t = 0;
    int done = 0;

    while (!done) {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;

                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    wt[i] = t - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

int main() {
    int n; // Number of processes
    printf("--------WELCOME!,THIS IS A CPU SCHEDULING SIMULATOR--------\n");
    sleep(1);
    printf("This program schedules processes according to the user input and gives a idea of how processes are scheduled and executed\n");
    sleep(1);
    printf("So ,LET'S START \n");
    sleep(1);
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct DiskRequest requests[n];
    int bt[n]; // Burst times of processes
    int wt[n]; // Waiting times
    int tat[n]; // Turnaround times
    int quantum; // Time quantum

    // Input burst times
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter the time quantum for RR: ");
    scanf("%d", &quantum);
    int choice;
    start:
    printf("Select a scheduling algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SJF\n");
    printf("3. Round Robin\n");
    printf("4. Priority Disk Scheduling\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("...You have selected FCFS SCHEDULING ALGORITHM...\n");
            fcfs(n, bt, wt, tat);
            break;
        case 2:
            printf("...You have selected SJF SCHEDULING ALGORITHM...\n");
            sjf(n, bt, wt, tat);
            break;
        case 3:
            rr(n, bt, wt, tat, quantum);
            printf("...You have selected ROUND ROBIN SCHEDULING ALGORITHM...\n");
            break;
        case 4:
            printf("...You have selected PRIORITY SCHEDULING ALGORITHM...\n");
            priorityDiskScheduling(n, requests, wt, tat);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

 printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate and display average waiting time and average turnaround time
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("WOHOO! , Here you can see the processes scheduled..\nTHANKYOU for using CPU SCHEDULING SIMULATOR...\n");
    int s;
    printf("To Implement any other scheduling algorithm press 1 and to exit press 2:\n");
    scanf("%d",&s);

switch(s)
        {
            case 1:
        goto start;
        break;
    case 2:
        return 0;
        break;

        }



    return 0;
}