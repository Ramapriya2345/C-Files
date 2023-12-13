//finding middle
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
}*start=NULL;

int findmid(struct node *p){
    int count=0;
    int sum=0;
    while(p!=NULL){
        count++;
        sum+=count;
        p=p->next;
    }
    int mid=sum/count;
    return mid;
}

struct node* getnode(int data) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

int main() {
    int n;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    int data;

    if (n <= 0) {
        printf("Invalid input for the number of nodes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct node* newNode = getnode(data);
        
        // Insert the new node at the beginning of the linked list
        newNode->next = start;
        start = newNode;
    }

    int mid = findmid(start);

    if (mid != -1) {
        printf("Middle: %d\n", mid);
    } else {
        printf("The list is empty.\n");
    }

    // Free the allocated memory for the linked list nodes
    struct node* temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }

    return 0;
}
