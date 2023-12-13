// #include <stdio.h>
// #include <stdlib.h>
// //stack implementation for prime numbers
// int stack_arr[100];
// int first=-1;
// void push(int data){
//     int i;
//     if(isFull()){
//         printf("Stack Overflow\n");
//         exit(1);
//     }
//     first++;
// for(i=first;i>0;i--){
//     stack_arr[i]=stack_arr[i-1];
//     }
//     stack_arr[0]=data;
// }
// int pop(){
//     int i,val;
//     if(isEmpty()){
//         printf("Stack Underflow\n");
//         return;
//     }
//     val=stack_arr[0];
//     for(i=0;i<first;i++){
//         stack_arr[i]=stack_arr[i+1];
//     }
//     first--;
//     return val;
// }
// void prime(int num){
//     int i=2;
//     while(num!=1){
//         while(num%i==0){
//             push(i);
//             num/=i;
//         }
//         i++;
//     }
// }
// int isEmpty(){
//     if(first==-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int peek(){
//     if(isEmpty()){
//         printf("stack underflow\n");
//         exit(1);
//     }
//     // return stack_arr[first];
//     return stack_arr[0];
// }
// int isFull(){
//     if(first==100-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void print(){
//     int i;
//     if(first==-1){
//         printf("Stack Underflow\n");
//         return;
//     }
//     for(i=0;i<=first;i++){
//         printf("%d ",stack_arr[i]);
//     }
// }
// int main(){
//     int num;
//     printf("Enter the number: ");
//     scanf("%d",&num);
//     prime(num);
//     print();
//     return 0;
// }

//using linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Stack Overflow\n");
        exit(1);
    }
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}
int pop(){
    struct node* temp;
    int val;
    if(top==NULL){
        printf("Stack Underflow\n");
        exit(1);
    }
    temp=top;
    val=temp->data;
    top=temp->next;
    free(temp);
    return val;
}
int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->data;
}
void print(){
    struct node* temp;
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    temp=top;
    while(temp->next!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}
void prime(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num/=i;
        }
        i++;
    }
}
int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    prime(num);
    print();
    printf("%d",pop());
    printf("%d",pop());
    // printf("%d",pop());
    // printf("%d",pop());
    printf("%d",peek());
    return 0;
}