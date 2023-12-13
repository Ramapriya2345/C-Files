#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack overloaded");
        exit(1);
    }
    printf("Enter the data to be pushed: ");
    scanf("%d", &newnode->data);
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int peek(struct node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->data;
}

int isEmpty(struct node *top)
{
    return (top == NULL);
}

void print(struct node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = top;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}

int main()
{
    struct node *top = NULL;
    int choice;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(&top);
            break;
        case 2:
            printf("The popped element is %d\n", pop(&top));
            break;
        case 3:
            printf("The top element is %d\n", peek(top));
            break;
        case 4:
            print(top);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
