#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
};
struct node *addtoempty(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node *insertatbegin(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node *insertatend(struct node *head,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    temp2->prev=NULL;
    temp2->data=data;
    temp2->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp2;
    temp2->prev=temp;
    temp2->next=NULL;
    return head;
}
struct node *insertbetween(struct node *head,int pos,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    struct node *ptr=NULL;
    temp2=addtoempty(temp2,data);
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        insertatend(head,data);
    }
    else{
    ptr=temp->next;
    temp->next=temp2;
    ptr->prev=temp2;
    temp2->prev=temp;
     temp2->next=ptr;
    return head;
    }  
}
struct node *insertafter(struct node *head,int element,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    struct node *ptr=NULL;
    temp2=addtoempty(temp2,data);
    while(temp->data!=element){
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertatend(head,data);
    }
    else{
    ptr=temp->next;
    temp->next=temp2;
    ptr->prev=temp2;
    temp2->next=ptr;
    temp2->prev=temp;
    return head;
    }  
}
struct node *insertbefore(struct node *head,int element,int data){
    struct node *temp=head;
    struct node *temp2=malloc(sizeof(struct node));
    struct node *ptr=NULL;
    temp2=addtoempty(temp2,data);
    while(temp->next->data!=element){
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertatend(head,data);
    }
    else{
    ptr=temp->next;
    temp->next=temp2;
    ptr->prev=temp2;
    temp2->next=ptr;
    temp2->prev=temp;
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
    free(head->prev);
    return head;
}
struct node *dellast(struct node *head){
    struct node *temp=head;
    struct node *temp2;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
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
    else{
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
    }
    return head;
}
struct node *delcurr(struct node *head,int element){
    struct node *temp=head;
    struct node *temp2=NULL;
    if(temp->data==element){
        head=delfirst(head);
        return head;
    }
    while(head->data!=element){
        temp=temp->next;
        head=head->next;
    }
    if(temp->next==NULL){
        head=dellast(head);
    }
    else{
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
    }
    return head;
}
struct node *delnext(struct node *head, int element) {
    struct node *temp = head;
    struct node *temp2 = NULL;
    if (temp == NULL || temp->next == NULL) {
        return head;
    }
    while (temp != NULL && temp->data != element) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2->next != NULL) {
            temp2->next->prev = temp;
        }
        free(temp2);
    }
    return head;
}
struct node *delbefore(struct node *head, int element) {
    struct node *temp = head;
    struct node *temp2 = NULL;
    if (temp == NULL || temp->next == NULL) {
        return head;
    }
    while (temp != NULL && temp->next->data != element) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
    }
    return head;
}
struct node* reverse(struct node* head) {
    struct node* current = head;
    struct node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }
    if (temp != NULL) {
        head = temp->prev;
    }
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
    head=insertbetween(head,2,23);
    head=insertafter(head,89,10);
    head=insertbefore(head,10,20);
    // head=insertnnodes(head);
    // printf("Before deletion\n");
    printf("Before reversal:");
    print(head);
    // head=delfirst(head);
    // head=dellast(head);
    // head=delatpos(head,2);
    printf("\n");
    // head=delcurr(head,78);
    // head=delnext(head,78);
    // head=delbefore(head,89);
    head=reverse(head);
    // printf("AFter deletion\n");
    // printf("After reversal:");
    print(head);
}