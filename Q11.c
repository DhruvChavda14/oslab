#include <stdio.h>

int main()
{
    int p, c, count = 0, i, j, alc[5][3], max[5][3], need[5][3], safe[5], available[3], done[5], terminate = 0;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &c);

    printf("Enter the allocation matrix for resources of all processes (%dx%d matrix):\n", p, c);
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &alc[i][j]);
        }
    }

    printf("Enter the max resource requirements for each process (%dx%d matrix):\n", p, c);
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for (i = 0; i < c; i++)
    {
        scanf("%d", &available[i]);
    }

    printf("\nNeed resources matrix is:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < c; j++)
        {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < p; i++)
    {
        done[i] = 0;
    }

    while (count < p)
    {
        for (i = 0; i < p; i++)
        {
            if (done[i] == 0)
            {
                for (j = 0; j < c; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        break;
                    }
                }
                if (j == c)
                {
                    safe[count] = i;
                    done[i] = 1;
                    for (j = 0; j < c; j++)
                    {
                        available[j] += alc[i][j];
                    }
                    count++;
                    terminate = 0;
                }
                else
                {
                    terminate++;
                }
            }
        }
        if (terminate == p)
        {
            printf("Safe sequence does not exist\n");
            break;
        }
    }

    if (terminate != p)
    {
        printf("\nAvailable resources after completion:\n");
        for (i = 0; i < c; i++)
        {
            printf("%d\t", available[i]);
        }
        printf("\nSafe sequence is:\n");
        for (i = 0; i < p; i++)
        {
            printf("p%d\t", safe[i]);
        }
        printf("\n");
    }

    return 0;
}

// input
// 5 3
// 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
// 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
// 3 3 2