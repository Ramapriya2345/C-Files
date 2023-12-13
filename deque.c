// // #include <stdio.h>
// // #include <stdlib.h>
// // #define MAX 5

// // int arr[MAX];
// // int front = -1;
// // int rear = -1;

// // void enqueue_front(int data) {
// //     if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
// //         printf("Queue is full, cannot insert at front\n");
// //     } else {
// //         if (front == -1) {
// //             front = 0;
// //             rear = 0;
// //         } else if (front == 0) {
// //             front = MAX - 1;
// //         } else {
// //             front--;
// //         }
// //         arr[front] = data;
// //     }
// // }

// // void enqueue_rear(int data) {
// //     if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
// //         printf("Queue is full, cannot insert at rear\n");
// //     } else {
// //         if (front == -1) {
// //             front = 0;
// //         }
// //         rear = (rear + 1) % MAX;
// //         arr[rear] = data;
// //     }
// // }

// // void print() {
// //     if (front == -1) {
// //         printf("Queue is empty\n");
// //     } else {
// //         int i = front;
// //         printf("Queue elements: ");
// //         while (1) {
// //             printf("%d ", arr[i]);
// //             if (i == rear) {
// //                 break;
// //             }
// //             i = (i + 1) % MAX;
// //         }
// //         printf("\n");
// //     }
// // }

// // void dequeue_front(){
// //     if (front == -1){
// //         printf("Queue is Empty \n");
// //     } else {
// //         printf("Deleted element: %d\n", arr[front]);
// //         if (front == rear) {
// //             front = rear = -1;
// //         } else {
// //             front = (front + 1) % MAX;
// //         }
// //     }
// // }

// // void dequeue_rear(){
// //     if (front == -1){
// //         printf("Queue is Empty \n");
// //     } else {
// //         printf("Deleted element: %d\n", arr[rear]);
// //         if (front == rear) {
// //             front = rear = -1;}
// //         // } else if (rear == 0) {
// //         //     rear = MAX - 1;
// //         // }
// //         else {
// //             // rear--;
// //             rear=(rear-1+MAX)%MAX;
// //         }
// //     }
// // }

// // int main() {
// //     enqueue_front(2);
// //     enqueue_front(3);
// //     enqueue_front(4);
// //     enqueue_rear(5);
// //     enqueue_rear(6);
// //     print();
// //     dequeue_front();
// //     dequeue_rear();
// //     print();
// //     return 0;
// // }

// // using singly linked
// // #include <stdio.h>
// // #include <stdlib.h>

// // struct node {
// //     int data;
// //     struct node *next;
// // }*front = NULL,*rear = NULL;

// // void enqueue_rear(int data) {
// //     struct node *newNode = (struct node *)malloc(sizeof(struct node));
// //     newNode->data = data;
// //     newNode->next = NULL;

// //     if (rear == NULL) {
// //         front = newNode;
// //     } else {
// //         rear->next = newNode;
// //     }
// //     rear = newNode;
// // }

// // void enqueue_front(int data) {
// //     struct node *newNode = (struct node *)malloc(sizeof(struct node));
// //     newNode->data = data;

// //     if (front == NULL) {
// //         newNode->next = NULL;
// //         rear = newNode;
// //     } else {
// //         newNode->next = front;
// //     }
// //     front = newNode;
// // }

// // void dequeue_front() {
// //     if (!front) {
// //         printf("Queue is empty\n");
// //     } else {
// //         struct node *temp = front;
// //         front = temp->next;
// //         free(temp);
// //     }
// // }

// // void dequeue_rear() {
// //     if (!front) {
// //         printf("Queue is Empty\n");
// //     } else {
// //         struct node *temp = front;
// //         if (temp->next == NULL) {
// //             front = rear = NULL;
// //             free(temp);
// //         } else {
// //             while (temp->next != rear) {
// //                 temp = temp->next;
// //             }
// //             temp->next = NULL;
// //             free(rear);
// //             rear = temp;
// //         }
// //     }
// // }

// // void print() {
// //     struct node *temp = front;
// //     while (temp != NULL) {
// //         printf("%d ", temp->data);
// //         temp = temp->next;
// //     }
// //     printf("\n");
// // }

// // int main() {
// //     enqueue_rear(5);
// //     enqueue_rear(4);
// //     print();
// //     enqueue_front(2);
// //     enqueue_front(3);
// //     print();
// //     dequeue_front();
// //     dequeue_rear();
// //     print();
// //     return 0;
// // }

// // using doubly linked list
// //  #include <stdio.h>
// //  #include <stdlib.h>

// // struct Node {
// //     int data;
// //     struct Node* next;
// //     struct Node* prev;
// // }* front = NULL,*rear=NULL;

// // void enqueue_front(int data) {
// //     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
// //     newNode->data = data;
// //     newNode->next = front;
// //     newNode->prev = NULL;

// //     if (front != NULL) {
// //         front->prev = newNode;
// //     } else {
// //         rear = newNode;
// //     }
// //     front = newNode;
// // }

// // void enqueue_rear(int data) {
// //     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
// //     newNode->data = data;
// //     newNode->next = NULL;
// //     newNode->prev = rear;

// //     if (rear != NULL) {
// //         rear->next = newNode;
// //     } else {
// //         front = newNode;
// //     }
// //     rear = newNode;
// // }

// // void print() {
// //     if (front == NULL) {
// //         printf("Queue is empty\n");
// //     } else {
// //         struct Node* current = front;
// //         printf("Queue elements: ");
// //         while (current != NULL) {
// //             printf("%d ", current->data);
// //             current = current->next;
// //         }
// //         printf("\n");
// //     }
// // }

// // void dequeue_front() {
// //     if (front == NULL) {
// //         printf("Queue is Empty \n");
// //     } else {
// //         struct Node* temp = front;
// //         printf("Deleted element: %d\n", temp->data);
// //         front = front->next;
// //         if (front != NULL) {
// //             front->prev = NULL;
// //         } else {
// //             rear = NULL;
// //         }
// //         free(temp);
// //     }
// // }

// // void dequeue_rear() {
// //     if (rear == NULL) {
// //         printf("Queue is Empty \n");
// //     } else {
// //         struct Node* temp = rear;
// //         printf("Deleted element: %d\n", temp->data);
// //         rear = rear->prev;
// //         if (rear != NULL) {
// //             rear->next = NULL;
// //         } else {
// //             front = NULL;
// //         }
// //         free(temp);
// //     }
// // }

// // int main() {
// //     enqueue_front(2);
// //     enqueue_front(3);
// //     enqueue_front(4);
// //     enqueue_rear(5);
// //     enqueue_rear(6);
// //     print();
// //     dequeue_front();
// //     dequeue_rear();
// //     print();
// //     return 0;
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 5

// int front = -1;
// int rear = -1;

// void enqueue_front(int *arr, int data)
// {
//     if ((front == 0 && rear == MAX - 1) || front == rear + 1)
//     {
//         printf("Queue is full, cannot insert at front\n");
//     }
//     else
//     {
//         if (front == -1)
//         {
//             front = 0;
//             rear = 0;
//         }
//         else if (front == 0)
//         {
//             front = MAX - 1;
//         }
//         else
//         {
//             front--;
//         }
//         arr[front] = data;
//     }
// }

// void enqueue_rear(int *arr, int data)
// {
//     if ((front == 0 && rear == MAX - 1) || front == rear + 1)
//     {
//         printf("Queue is full, cannot insert at rear\n");
//     }
//     else
//     {
//         if (front == -1)
//         {
//             front = 0;
//         }
//         rear = (rear + 1) % MAX;
//         arr[rear] = data;
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

// void dequeue_front(int *arr)
// {
//     if (front == -1)
//     {
//         printf("Queue is Empty \n");
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

// void dequeue_rear(int *arr)
// {
//     if (front == -1)
//     {
//         printf("Queue is Empty \n");
//     }
//     else
//     {
//         printf("Deleted element: %d\n", arr[rear]);
//         if (front == rear)
//         {
//             front = rear = -1;
//         }
//         else
//         {
//             rear = (rear - 1 + MAX) % MAX;
//         }
//     }
// }

// int main()
// {
//     int arr[MAX]; // Declared locally inside main
//     int choice, data;

//     while (1)
//     {
//         printf("1. Enqueue Front\n");
//         printf("2. Enqueue Rear\n");
//         printf("3. Dequeue Front\n");
//         printf("4. Dequeue Rear\n");
//         printf("5. Print\n");
//         printf("6. Quit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data to be inserted at front: ");
//             scanf("%d", &data);
//             enqueue_front(arr, data);
//             break;
//         case 2:
//             printf("Enter the data to be inserted at rear: ");
//             scanf("%d", &data);
//             enqueue_rear(arr, data);
//             break;
//         case 3:
//             dequeue_front(arr);
//             break;
//         case 4:
//             dequeue_rear(arr);
//             break;
//         case 5:
//             print(arr);
//             break;
//         case 6:
//             exit(0);
//         default:
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// } *front = NULL, *rear = NULL;

// void enqueue_rear(int data)
// {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (rear == NULL)
//     {
//         front = newNode;
//     }
//     else
//     {
//         rear->next = newNode;
//     }
//     rear = newNode;
// }

// void enqueue_front(int data)
// {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->data = data;

//     if (front == NULL)
//     {
//         newNode->next = NULL;
//         rear = newNode;
//     }
//     else
//     {
//         newNode->next = front;
//     }
//     front = newNode;
// }

// void dequeue_front()
// {
//     if (!front)
//     {
//         printf("Queue is empty\n");
//     }
//     else
//     {
//         struct node *temp = front;
//         front = temp->next;
//         free(temp);
//     }
// }

// void dequeue_rear()
// {
//     if (!front)
//     {
//         printf("Queue is Empty\n");
//     }
//     else
//     {
//         struct node *temp = front;
//         if (temp->next == NULL)
//         {
//             front = rear = NULL;
//             free(temp);
//         }
//         else
//         {
//             while (temp->next != rear)
//             {
//                 temp = temp->next;
//             }
//             temp->next = NULL;
//             free(rear);
//             rear = temp;
//         }
//     }
// }

// void print()
// {
//     struct node *temp = front;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main()
// {
//     int choice, data;

//     while (1)
//     {
//         printf("1. Enqueue Rear\n");
//         printf("2. Enqueue Front\n");
//         printf("3. Dequeue Front\n");
//         printf("4. Dequeue Rear\n");
//         printf("5. Print\n");
//         printf("6. Quit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data to be inserted at rear: ");
//             scanf("%d", &data);
//             enqueue_rear(data);
//             break;
//         case 2:
//             printf("Enter the data to be inserted at front: ");
//             scanf("%d", &data);
//             enqueue_front(data);
//             break;
//         case 3:
//             dequeue_front();
//             break;
//         case 4:
//             dequeue_rear();
//             break;
//         case 5:
//             print();
//             break;
//         case 6:
//             exit(0);
//         default:
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *front = NULL, *rear = NULL;

void enqueue_front(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = front;
    newNode->prev = NULL;

    if (front != NULL)
    {
        front->prev = newNode;
    }
    else
    {
        rear = newNode;
    }
    front = newNode;
}

void enqueue_rear(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear != NULL)
    {
        rear->next = newNode;
    }
    else
    {
        front = newNode;
    }
    rear = newNode;
}

void print()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *current = front;
        printf("Queue elements: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void dequeue_front()
{
    if (front == NULL)
    {
        printf("Queue is Empty \n");
    }
    else
    {
        struct Node *temp = front;
        printf("Deleted element: %d\n", temp->data);
        front = front->next;
        if (front != NULL)
        {
            front->prev = NULL;
        }
        else
        {
            rear = NULL;
        }
        free(temp);
    }
}

void dequeue_rear()
{
    if (rear == NULL)
    {
        printf("Queue is Empty \n");
    }
    else
    {
        struct Node *temp = rear;
        printf("Deleted element: %d\n", temp->data);
        rear = rear->prev;
        if (rear != NULL)
        {
            rear->next = NULL;
        }
        else
        {
            front = NULL;
        }
        free(temp);
    }
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Print\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted at front: ");
            scanf("%d", &data);
            enqueue_front(data);
            break;
        case 2:
            printf("Enter the data to be inserted at rear: ");
            scanf("%d", &data);
            enqueue_rear(data);
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            print();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
