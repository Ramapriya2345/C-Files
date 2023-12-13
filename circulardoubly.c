#include <stdio.h>
#include <stdlib.h>
//circular doubly linked list
struct node {
    int data;
    struct node *prev, *next;
};

void print(struct node *head);
struct node *addtoempty(struct node *head, int data);
struct node *insertb(struct node *head, int data);
struct node *insertatend(struct node *head, int data);
struct node *insertbetween(struct node *head, int pos, int data);
struct node *insertnnodes(struct node *head);
struct node *delfirst(struct node *head);
struct node *dellast(struct node *head);
struct node *delatpos(struct node *head, int pos);
struct node *reverse(struct node *head);

int main() {
    struct node *head = NULL;
    head = addtoempty(head, 89);
    head = insertb(head, 78);
    head=insertb(head,10);
    head = insertatend(head, 35);
    head = insertbetween(head, 5, 23);
    // // head = insertnnodes(head);
    // printf("Before deletion\n");
    print(head);
    // head = delfirst(head);
    // head = dellast(head);
    // head = delatpos(head, 1);
    head=reverse(head);
    // printf("\n");
    // // printf("After deletion\n");
    // printf("After reversal:");
    print(head);
    return 0;
}

struct node *addtoempty(struct node *head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    head = temp;
    return head;
}

// struct node *insertb(struct node *head, int data) {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->next = head;
//     temp->prev = head->prev;
//     head->prev->next = temp;
//     head->prev = temp;
//     head = temp;
//     return head;
// }
// // or
struct node *insertb(struct node *tail,int data){
    struct node *new=addtoempty(new,data);
    if(tail==NULL){
        return new;
    }
    else{
        struct node *temp=tail->next;
        new->next=temp;
        new->prev=tail;
        temp->prev=new;
        tail->next=new;
        return tail;     
    }
}
struct node *insertatend(struct node *tail, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next=NULL;
    struct node *ptr=tail->next;
    temp->next=ptr;
    ptr->prev=temp;
    tail->next=temp;
    temp->prev = tail;
    tail=temp;
    return tail;
}
struct node *insertbetween(struct node *tail, int pos, int data) {
    struct node *temp = tail->next;
    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = NULL;
    temp2 = addtoempty(temp2, data);
    while (pos > 2) {
        temp = temp->next;
        pos--;
    }
    if(temp==tail){
        tail=insertatend(tail,data);
        return tail;
    }
    ptr = temp->next;
    temp->next = temp2;
    ptr->prev = temp2;
    temp2->next = ptr;
    temp2->prev = temp;
    return tail;
}
void print(struct node *head) {
    struct node *ptr = head->next;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head->next);
    printf("\n");
}

struct node *delfirst(struct node *tail){
  struct node *ptr=tail->next;
  tail->next=ptr->next;
  ptr->next->prev=tail;
  free(ptr);
  return tail;
}
struct node *dellast(struct node *tail){
    struct node *temp=tail->prev;
    temp->next=tail->next;
    tail->next->prev=temp;
    tail=temp;
    return tail;
}
struct node *delatpos(struct node *tail,int pos){
    struct node *temp=tail->next;
    struct node *temp2=NULL;
    if(pos==1){
        tail=delfirst(tail);
        return tail;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp==tail){
        tail=dellast(tail);
    }
    else{
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
    }
    return tail;
}
struct node *reverse(struct node *tail){
    struct node *temp=NULL;
    struct node *ptr=tail->next;
    struct node *temp2=ptr->next;
    while(ptr!=tail){
        temp=ptr;
        ptr=temp2;
        temp2=ptr->next;
        ptr->next->prev=temp2;
        ptr->next=temp;
        temp->prev=ptr;
    };
    temp2->next=tail;
    tail->prev=temp2;
    tail=temp2;
    return tail;
}
//0r
// void print(struct node *head) {
//     struct node *ptr = head;
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     do {
//         printf("%d -> ", ptr->data);
//         ptr = ptr->next;
//     } while (ptr != head);
//     printf("\n");
// }
