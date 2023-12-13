// array implementation of queue
#include <stdio.h>
#include <stdlib.h>
int queue_arr[100];
int front = -1;
int rear = -1;
void insert(int data)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        exit(1);
    }
    if (front == -1)
    {
        front = 0;
    }
    queue_arr[++rear] = data;
}
int delete()
{
    int val;
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    val = queue_arr[front++];
    return val;
}
int isEmpty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if (rear == 100 - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}
void print()
{
    int i;
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue_arr[i]);
    }
    printf("\n");
}
int main()
{
    int choice, data;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Peek\n");
        printf("4.Print\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted : ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("The deleted element is : %d\n", delete ());
            break;
        case 3:
            printf("The element at the front is : %d\n", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

// linked list implementation of queue
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Queue Overflow\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    if (front == NULL)
    {
        front = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}
int delete()
{
    struct node *temp;
    int val;
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    temp = front;
    val = temp->data;
    front = temp->next;
    free(temp);
    return val;
}
int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return front->data;
}
void print()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, data;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Peek\n");
        printf("4.Print\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted : ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("The deleted element is : %d\n", delete ());
            break;
        case 3:
            printf("The element at the front is : %d\n", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void insert(int *queue_arr, int data)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        exit(1);
    }
    if (front == -1)
    {
        front = 0;
    }
    queue_arr[++rear] = data;
}

int delete(int *queue_arr)
{
    int val;
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    val = queue_arr[front++];
    return val;
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return (rear == 100 - 1);
}

int peek(int *queue_arr)
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}

void print(int *queue_arr)
{
    int i;
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue_arr[i]);
    }
    printf("\n");
}

int main()
{
    int queue_arr[100]; // Declared locally inside main
    int choice, data;

    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Peek\n");
        printf("4.Print\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted : ");
            scanf("%d", &data);
            insert(queue_arr, data);
            break;
        case 2:
            printf("The deleted element is : %d\n", delete (queue_arr));
            break;
        case 3:
            printf("The element at the front is : %d\n", peek(queue_arr));
            break;
        case 4:
            print(queue_arr);
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
