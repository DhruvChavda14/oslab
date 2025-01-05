#include <stdio.h>

int main()
{
    int bt[20], p[20], pri[20], wt[20], tat[20], i, j, n, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time and Priority:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst time p%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Priority p%d: ", i + 1);
        scanf("%d", &pri[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pri[j] < pri[pos])
            {
                pos = j;
            }
        }

        temp = pri[i];
        pri[i] = pri[pos];
        pri[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        total += wt[i];
    }

    avg_wt = (float)total / n;

    printf("\nProcess\t Burst Time \tPriority \t Waiting Time\t Turnaround Time\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        totalT += tat[i];
        printf("p%d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    avg_tat = (float)totalT / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
