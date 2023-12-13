#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top = -1;
void push(int data);
int pop();
void print();
int isFull();
int isEmpty();
int peek();
int main()
{
    int choice, data;
    while (1)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all elements\n");
        printf("5. Quit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Element to be pushed:");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted element; %d\n", data);
            break;
        case 3:
            printf("Top most element: %d\n", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice");
        }
    }
}
void push(int data)
{
    if (isFull())
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack_arr[top] = data;
}
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    int val = stack_arr[top];
    top--;
    return val;
}
void print()
{
    int i;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}
int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (top == -1)
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
        printf("stack underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

//   push(1);
//   push(2);
//   push(3);
//   push(4);
// //   push(5);
//   data=pop();
//   data=pop();
//   print();
//   printf("%d",data);