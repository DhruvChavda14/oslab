#include <stdio.h>
#include<stdlib.h>
int mutex = 1, full = 0, empty = 3, x = 0;

void producer();
void consumer();
int wait_custom(int);
int signal_custom(int);

int main()
{
    int n;
    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");

    while (1)
    {
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("BUFFER IS FULL\n");
            }
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("BUFFER IS EMPTY\n");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}

int wait_custom(int s)
{
    return (--s);
}

int signal_custom(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait_custom(mutex);
    full = signal_custom(full);
    empty = wait_custom(empty);
    x++;
    printf("\nProducer produces the item %d", x);
    mutex = signal_custom(mutex);
}

void consumer()
{
    mutex = wait_custom(mutex);
    full = wait_custom(full);
    empty = signal_custom(empty);
    printf("\nConsumer consumes item %d", x);
    x--;
    mutex = signal_custom(mutex);
}
