#include <stdio.h>

int main()
{
    int pid[15], bt[15], n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process ID of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    int wt[n];
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("Process ID Burst Time Waiting Time Turnaround Time\n");
    float twt = 0.0, tat = 0.0;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", bt[i] + wt[i]);
        printf("\n");
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }

    float awt = twt / n;
    float att = tat / n;

    printf("Avg. waiting time = %.2f\n", awt);
    printf("Avg. turnaround time = %.2f\n", att);

    return 0;
}
