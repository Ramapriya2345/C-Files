#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *addtoempty(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node *insertatbegin(struct node *tail,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=tail->next;
    tail->next=temp;
    return tail;
}
struct node *insertatend(struct node *tail,int data){
    struct node *temp2=malloc(sizeof(struct node));
    temp2->data=data;
    temp2->next=NULL;
    temp2->next=tail->next;
    tail->next=temp2;
    tail=tail->next;
    return tail;
}
struct node *insertbetween(struct node *tail,int pos,int data){
    struct node *temp=tail->next;
    struct node *temp2=malloc(sizeof(struct node));
    temp2=addtoempty(data);
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    temp2->next=temp->next;
    temp->next=temp2;
    if(temp==tail){
        tail=tail->next;
    }
    return tail;
}
// struct node *insertafter(struct node *tail,int element,int data){
//     struct node *temp=tail->next;
//     struct node *temp2=malloc(sizeof(struct node));
//     temp2=addtoempty(data);
//     if(temp->data==element){
//         insertatbegin(tail,data);
//     }
//     while(temp->data!=element){
//         temp=temp->next;
//     }
//     if(temp->next==NULL){
//         insertatend(tail,data);
//     }
//     else{
//     temp2->next=temp->next;
//     temp->next=temp2;
//     return tail;
//     }  
// }
// struct node *insertbefore(struct node *tail,int element,int data){
//     struct node *temp=tail;
//     struct node *temp2=malloc(sizeof(struct node));
//     struct node *ptr=NULL;
//     temp2=addtoempty(temp2,data);
//     if(temp->data==element){
//         temp2->next=temp;
//         return temp2;
//     }
//     while(temp->next->data!=element){
//         temp=temp->next;
//     }
//     if(temp->next==NULL){
//         insertatend(tail,data);
//     }
//     else{
//     ptr=temp->next;
//     temp->next=temp2;
//     temp2->next=ptr;
//     return tail;
//     }  
// }
// struct node *insertnnodes(struct node *tail){
//     int n;
//     printf("Enter no of nodes:");
//     scanf("%d",&n);
//     if(n==0){
//         return tail;
//     }
//    int data;
//     for(int i=0;i<n;i++){
//         scanf("%d",&data);
//         tail=insertatend(tail,data);
//     }
//     return tail;
// }
struct node *delfirst(struct node *tail){
    if(tail->next==tail){
        free(tail);
        tail=NULL;
    }
    struct node *p=tail->next;
    tail->next=p->next;
    free(p);
    return tail;
}
struct node *dellast(struct node *tail){
    struct node *temp=tail->next;
    if(tail->next==tail){
        free(tail);
        tail=NULL;
    }
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    tail=temp;
    return tail;
}
struct node *delatpos(struct node *tail,int pos){
    struct node *temp=tail;
    struct node *temp2=NULL;
    if(pos==1){
        tail=delfirst(tail);
        return tail;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==tail){
        tail=dellast(tail);
    }
    else{
        temp2=temp->next;
        temp->next=temp2->next;
    }
    return tail;
}
// struct node *delafter(struct node *tail, int element) {
//     struct node *temp = tail;
//     struct node *temp2 = NULL;

//     if (tail->data == element) {
//         tail = delfirst(tail); 
//         return tail;
//     }
//     while (temp != NULL && temp->data != element) {
//         temp2 = temp;
//         temp = temp->next;
//     }
//     temp2=temp;
//     temp=temp->next;
//     if (temp != NULL && temp->next != NULL) {
//         temp2->next = temp->next;
//         free(temp); 
//     } else {
//     tail = dellast(tail);
//     }

//     return tail;
// }
// struct node *delcurr(struct node *tail, int element) {
//     struct node *temp = tail;
//     struct node *temp2 = NULL;

//     if (tail->data == element) {
//         tail = delfirst(tail); 
//         return tail;
//     }
//     while (temp != NULL && temp->data != element) {
//         temp2 = temp;
//         temp = temp->next;
//     }
//     if (temp != NULL && temp->next != NULL) {
//         temp2->next = temp->next;
//         free(temp); 
//     } else {
//        tail = dellast(tail);
//     }

//     return tail;
// }
// struct node *delbefore(struct node *tail, int element) {
//     struct node *temp = tail;
//     struct node *temp2 = NULL;

//     if (tail->data == element) {
//         tail = delfirst(tail); 
//         return tail;
//     }
//     while (temp != NULL && temp->next->data != element) {
//         temp2 = temp;
//         temp = temp->next;
//     }

//     if (temp != NULL && temp->next != NULL) {
//         temp2->next = temp->next;
//         free(temp); 
//     } else {
//        tail = dellast(tail);
//     }

//     return tail;
// }
struct node *reverse(struct node *tail){
    struct node *temp=NULL;
    struct node *ptr=tail->next;
    struct node *temp2=ptr->next;
    while(ptr!=tail){
        temp=ptr;
        ptr=temp2;
        temp2=ptr->next;
        ptr->next=temp;
    };
    temp2->next=tail;
    tail=temp2;
    return tail;
}
void print(struct node *tail){
    struct node *ptr=tail->next;
    do{
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}
int main(){
    struct node *tail=(struct node*)malloc(sizeof(struct node));
    tail=addtoempty(89);
    // printf("%d",tail->data);
    tail=insertatbegin(tail,78);
    tail=insertatend(tail,35);
    tail=insertatend(tail,29);
    tail=insertatend(tail,10);
    tail=insertatend(tail,15);
    // tail=insertbetween(tail,3,23);
    // tail=insertafter(tail,78,10);
    // tail=insertbefore(tail,10,20);  
    // tail=insertnnodes(tail);
    // printf("Before deletion\n");
    // printf("Before reversal:");
    print(tail);
    // tail=delfirst(tail);
    // tail=dellast(tail);
    // tail=delatpos(tail,4);
    printf("\n");
    // tail=delcurr(tail,10);
    // tail=delafter(tail,35);
    // tail=delbefore(tail,35);
    tail=reverse(tail);
    // printf("AFter deletion\n");
    // printf("After reversal:");
    print(tail);
}
//for counting..include an additional count++ to count.