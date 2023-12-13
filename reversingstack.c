//reversing a stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int first=-1;
void push(int data){
    int i;
    if(isFull()){
        printf("Stack Overflow\n");
        exit(1);
    }
    first++;
for(i=first;i>0;i--){
    stack_arr[i]=stack_arr[i-1];
}
stack_arr[0]=data;
}
int pop(){
    int i,val;
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    val=stack_arr[0];
    for(i=0;i<first;i++){
        stack_arr[i]=stack_arr[i+1];
    }
    first--;
    return val;
}
int isEmpty(){
    if(first==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(){
    if(isEmpty()){
        printf("stack underflow\n");
        exit(1);
    }
    // return stack_arr[first];
    return stack_arr[0];
}
int isFull(){
    if(first==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
void print(){
    int i;
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    for(i=0;i<=first;i++){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}
void reverse(){
    int i,j,temp;
    for(i=0,j=first;i<j;i++,j--){
        temp=stack_arr[i];
        stack_arr[i]=stack_arr[j];
        stack_arr[j]=temp;
    }
}
int main(){
    int choice,data;
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Print\n");
        printf("5.Reverse\n");
        printf("6.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the data to be pushed: ");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            printf("The popped element is: %d\n",pop());
            break;
            case 3:
            printf("The top element is: %d\n",peek());
            break;
            case 4:
            print();
            break;
            case 5:
            reverse();
            break;
            case 6:
            exit(1);
            default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
