#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int top = -1;

void push(int *stack, int data);
int pop(int *stack);
void print(int *stack);
int isFull();
int isEmpty();
int peek(int *stack);

int main()
{
    int choice, data;
    int *stack = malloc(MAX * sizeof(int));

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
            push(stack, data);
            break;
        case 2:
            data = pop(stack);
            printf("Deleted element: %d\n", data);
            break;
        case 3:
            printf("Top most element: %d\n", peek(stack));
            break;
        case 4:
            print(stack);
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice");
        }
    }
    return 0;
}

void push(int *stack, int data)
{
    if (isFull())
    {
        printf("Stack Overflow");
        return;
    }
    stack[top++] = data;
}

int pop(int *stack)
{
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    int val = stack[top--];
    return val;
}

void print(int *stack)
{
    int i;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
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

int peek(int *stack)
{
    if (isEmpty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return stack[top];
}
