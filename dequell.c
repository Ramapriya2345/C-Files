#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Deque {
    struct Node *front, *rear;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Deque *createDeque() {
    struct Deque *dq = (struct Deque *)malloc(sizeof(struct Deque));
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

void insertFront(struct Deque *dq, int data) {
    struct Node *newNode = createNode(data);
    if (dq->front == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void insertRear(struct Deque *dq, int data) {
    struct Node *newNode = createNode(data);
    if (dq->rear == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

void deleteFront(struct Deque *dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
    } else {
        struct Node *temp = dq->front;
        dq->front = dq->front->next;
        if (dq->front == NULL) {
            dq->rear = NULL;
        } else {
            dq->front->prev = NULL;
        }
        free(temp);
    }
}

void deleteRear(struct Deque *dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty.\n");
    } else {
        struct Node *temp = dq->rear;
        dq->rear = dq->rear->prev;
        if (dq->rear == NULL) {
            dq->front = NULL;
        } else {
            dq->rear->next = NULL;
        }
        free(temp);
    }
}

void printDeque(struct Deque *dq) {
    struct Node *temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque *dq = createDeque();
    insertFront(dq, 5);
    insertFront(dq, 10);
    insertRear(dq, 15);
    insertRear(dq, 20);

    printf("Initial deque: ");
    printDeque(dq);

    deleteFront(dq);
    deleteRear(dq);

    printf("Deque after deletions: ");
    printDeque(dq);

    return 0;
}
