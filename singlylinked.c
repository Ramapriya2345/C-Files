#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *addtoempty(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node *insertatbegin(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head=temp;
    return head;
}
struct node *insertatend(struct node *head,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    temp2->data=data;
    temp2->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp2;
    return head;
}
struct node *insertbetween(struct node *head,int pos,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    struct node *ptr=NULL;
    temp2=addtoempty(temp2,data);
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        insertatend(head,data);
    }
    else{
    ptr=temp->next;
    temp->next=temp2;
    temp2->next=ptr;
    return head;
    }  
}
struct node *insertafter(struct node *head,int element,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    struct node *ptr=NULL;
    temp2=addtoempty(temp2,data);
    if(temp->data==element){
        insertatbegin(head,data);
    }
    while(temp->data!=element){
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertatend(head,data);
    }
    else{
    ptr=temp->next;
    temp->next=temp2;
    temp2->next=ptr;
    return head;
    }  
}
struct node *insertbefore(struct node *head,int element,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    struct node *ptr=NULL;
    temp2=addtoempty(temp2,data);
    if(temp->data==element){
        temp2->next=temp;
        return temp2;
    }
    while(temp->next->data!=element){
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertatend(head,data);
    }
    else{
    ptr=temp->next;
    temp->next=temp2;
    temp2->next=ptr;
    return head;
    }  
}
struct node *insertnnodes(struct node *head){
    int n;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    if(n==0){
        return head;
    }
   int data;
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head=insertatend(head,data);
    }
    return head;
}
struct node *delfirst(struct node *head){
    head=head->next;
    return head;
}
struct node *dellast(struct node *head){
    struct node *temp=head;
    struct node *temp2;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    free(temp);
    return head;
}
struct node *delatpos(struct node *head,int pos){
    struct node *temp=head;
    struct node *temp2=NULL;
    if(pos==1){
        head=delfirst(head);
        return head;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        head=dellast(head);
    }
    // else{
    //     temp2=temp->next;
    //     temp->next=temp2->next;
    // }
    return head;
}
struct node *delafter(struct node *head, int element) {
    struct node *temp = head;
    struct node *temp2 = NULL;

    if (head->data == element) {
        head = delfirst(head); 
        return head;
    }
    while (temp != NULL && temp->data != element) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2=temp;
    temp=temp->next;
    if (temp != NULL && temp->next != NULL) {
        temp2->next = temp->next;
        free(temp); 
    } else {
    head = dellast(head);
    }

    return head;
}
struct node *delcurr(struct node *head, int element) {
    struct node *temp = head;
    struct node *temp2 = NULL;

    if (head->data == element) {
        head = delfirst(head); 
        return head;
    }
    while (temp != NULL && temp->data != element) {
        temp2 = temp;
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        temp2->next = temp->next;
        free(temp); 
    } else {
       head = dellast(head);
    }

    return head;
}
struct node *delbefore(struct node *head, int element) {
    struct node *temp = head;
    struct node *temp2 = NULL;

    if (head->data == element) {
        head = delfirst(head); 
        return head;
    }
    while (temp != NULL && temp->next->data != element) {
        temp2 = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        temp2->next = temp->next;
        free(temp); 
    } else {
       head = dellast(head);
    }

    return head;
}
struct node *reverse(struct node *head){
    struct node *temp=NULL;
    struct node *temp2=NULL;
    while(head!=NULL){
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;
    return head;
}
void print(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head=addtoempty(head,89);
    head=insertatbegin(head,78);
    head=insertatend(head,35);
    head=insertatend(head,29);
    head=insertbetween(head,3,23);
    // head=insertafter(head,78,10);
    // head=insertbefore(head,10,20);  
    // head=insertnnodes(head);
    // printf("Before deletion\n");
    // printf("Before reversal:");
    print(head);
    // head=delfirst(head);
    // head=dellast(head);
    // head=delatpos(head,3);
    printf("\n");
    // head=delcurr(head,10);
    // head=delafter(head,10);
    // head=delbefore(head,35);
    head=reverse(head);
    // printf("AFter deletion\n");
    printf("After reversal:");
    print(head);
}
