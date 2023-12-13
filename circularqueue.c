#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int arr[MAX];
int front = -1;
int rear = -1;

void insert(int data)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = data;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", arr[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void print()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        printf("Queue elements: ");
        while (1)
        {
            printf("%d ", arr[i]);
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(7);
    insert(8);
    print();
    delete (); // Delete the first element
    delete ();
    print();
    insert(9); // Insert 9 into the queue
    insert(10);
    print();
    for (int i = 0; i <= 4; i++)
    {
        printf("element : %d ", arr[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (front == NULL)
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }
    rear = newNode;
    rear->next = front;
}

void delete()
{
    if (front == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        struct Node *temp = front;
        printf("Deleted element: %d\n", front->data);
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
        free(temp);
    }
}

void print()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *temp = front;
        printf("Queue elements: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            delete ();
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 5

// int front = -1;
// int rear = -1;

// void insert(int *arr, int data)
// {
//     if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
//     {
//         printf("Overflow\n");
//     }
//     else
//     {
//         if (front == -1)
//         {
//             front = 0;
//         }
//         rear = (rear + 1) % MAX;
//         arr[rear] = data;
//         printf("Inserted element: %d\n", data);
//     }
// }

// void delete(int *arr)
// {
//     if (front == -1)
//     {
//         printf("Underflow\n");
//     }
//     else
//     {
//         printf("Deleted element: %d\n", arr[front]);
//         if (front == rear)
//         {
//             front = rear = -1;
//         }
//         else
//         {
//             front = (front + 1) % MAX;
//         }
//     }
// }

// void print(int *arr)
// {
//     if (front == -1)
//     {
//         printf("Queue is empty\n");
//     }
//     else
//     {
//         int i = front;
//         printf("Queue elements: ");
//         while (1)
//         {
//             printf("%d ", arr[i]);
//             if (i == rear)
//             {
//                 break;
//             }
//             i = (i + 1) % MAX;
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int arr[MAX]; // Declared locally inside main
//     int choice, data;

//     while (1)
//     {
//         printf("1. Insert\n");
//         printf("2. Delete\n");
//         printf("3. Print\n");
//         printf("4. Quit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data to be inserted: ");
//             scanf("%d", &data);
//             insert(arr, data);
//             break;
//         case 2:
//             delete (arr);
//             break;
//         case 3:
//             print(arr);
//             break;
//         case 4:
//             exit(0);
//         default:
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }
