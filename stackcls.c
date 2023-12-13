#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int push(int *arr, int data, int *top);
int pop(int *arr, int *top);
int isFull(int *top);
int isEmpty(int *top);
void print(int *arr, int *top);
int push(int *arr, int data, int *top) {
    if (isFull(top)) {
        printf("Overflow\n");
        exit(1);
    }
    arr[++(*top)] = data;
    return *top;
}

int pop(int *arr, int *top) {
    if (isEmpty(top)) {
        printf("Underflow\n");
        exit(1);
    }
    int val = arr[(*top)--];
    return val;
}

int isFull(int *top) {
    return (*top == MAX - 1);
}

int isEmpty(int *top) {
    return (*top == -1);
}

void print(int *arr, int *top) {
    int i;
    if (isEmpty(top)) {
        printf("S5tack Underflow\n");
        return;
    }
    for (i = *top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *stack_arr = malloc(sizeof(int) * MAX);
    int top = -1;
    int choice,data;
    while(1){
    printf("\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print all elements\n");
    printf("4. Quit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter data to be pushed:");
        scanf("%d",&data);
        push(stack_arr,data,&top);
        break;
    case 2:
        data=pop(stack_arr,&top);
        printf("Deleted element: %d\n",data);
        break;
    case 3:
        print(stack_arr,&top);
        break;
    case 4:
        exit(1);
    default:
        printf("Wrong choice");
        break;
    }
}
}
