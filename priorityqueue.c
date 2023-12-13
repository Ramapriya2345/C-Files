#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int prio;
    struct Node *next;
} *front = NULL;
void enqueue(int data, int prio)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prio = prio;

    if (front == NULL || prio < front->prio)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        struct Node *current = front;
        while (current->next != NULL && current->next->prio <= prio)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        printf("Dequeued element: %d\n", temp->data);
        free(temp);
    }
}

void print()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        struct Node *current = front;
        printf("Queue elements: ");
        while (current != NULL)
        {
            printf("(%d, %d) ", current->data, current->prio);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    int data, prio;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d%d", &data, &prio);
        enqueue(data, prio);
    }
    print();
    dequeue();
    print();
    return 0;
}

// array implementation of the same#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5    // Maximum number of prio levels
#define SIZE 100 // Maximum size of each queue

void enqueue(int **prioQueue, int *front, int *rear, int data, int prio)
{
    if (rear[prio] == SIZE - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front[prio] == -1)
        {
            front[prio] = 0;
        }
        rear[prio]++;
        prioQueue[prio][rear[prio]] = data;
    }
}

void dequeue(int **prioQueue, int *front, int *rear)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (front[i] != -1)
        {
            printf("Dequeued element with prio %d: %d\n", i, prioQueue[i][front[i]]);
            prioQueue[i][front[i]] = 0;
            if (front[i] == rear[i])
            {
                front[i] = rear[i] = -1;
            }
            else
            {
                front[i]++;
            }
            return;
        }
    }
    printf("Queue underflow\n");
}

void printQueue(int **prioQueue, int *front, int *rear)
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        printf("Queue with prio %d: ", i);
        if (front[i] != -1)
        {
            for (j = front[i]; j <= rear[i]; j++)
            {
                printf("%d ", prioQueue[i][j]);
            }
        }
        else
        {
            printf("Empty");
        }
        printf("\n");
    }
}

int main()
{
    int **prioQueue = (int **)malloc(MAX * sizeof(int *));
    int *front = (int *)malloc(MAX * sizeof(int));
    int *rear = (int *)malloc(MAX * sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        prioQueue[i] = (int *)malloc(SIZE * sizeof(int));
        front[i] = -1;
        rear[i] = -1;
    }

    // Enqueue elements
    enqueue(prioQueue, front, rear, 10, 0);
    enqueue(prioQueue, front, rear, 20, 1);
    enqueue(prioQueue, front, rear, 30, 2);
    enqueue(prioQueue, front, rear, 40, 2);
    enqueue(prioQueue, front, rear, 50, 1);
    enqueue(prioQueue, front, rear, 60, 3);

    // Print elements of the prio queue
    printf("After Enqueue:\n");
    printQueue(prioQueue, front, rear);

    // Dequeue elements
    dequeue(prioQueue, front, rear);
    dequeue(prioQueue, front, rear);
    dequeue(prioQueue, front, rear);
    dequeue(prioQueue, front, rear);
    dequeue(prioQueue, front, rear);
    dequeue(prioQueue, front, rear);
    dequeue(prioQueue, front, rear);

    // Print elements of the prio queue after dequeue
    printf("\nAfter Dequeue:\n");
    printQueue(prioQueue, front, rear);

    // Free memory
    for (int i = 0; i < MAX; i++)
    {
        free(prioQueue[i]);
    }
    free(prioQueue);
    free(front);
    free(rear);

    return 0;
}
