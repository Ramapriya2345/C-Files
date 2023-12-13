//array implementation of queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue_arr[MAX];
int front=-1;
int rear=-1;
void enqueue(int data){
    if((front==0 && rear==MAX-1)|| (front==rear+1)){
        printf("Queue Overflow\n");
        exit(1);
    }
    if(front==-1){
        front=0;
    }
    queue_arr[++rear]=data;
}
void dequeue(){
    int val;
    if(front=rear==-1){
        printf("Queue Underflow\n");
        exit(1);
    }
    val=queue_arr[front];
    free(queue_arr[front]);
    queue_arr[front]==NULL;
    front++;
}
void print(){
    int i;
        if(front==0){
            for(i=0;i<=rear;i++){
            printf("%d ",queue_arr[i]);
        }
        }
        else{
            for(i=front;queue_arr[i]!=NULL;i++){
                printf("%d ",queue_arr[i]);
            }
            for(i=0;i<front;i++){
                 printf("%d ",queue_arr[i]);
            }
        }     
    printf("\n");
}
int main(){
     enqueue(1);
     enqueue(2);
     enqueue(3);
     print();
     dequeue();
     print();
     enqueue(4);
     print();
     dequeue();
     dequeue();
     print();
     enqueue(5);
     print();
     dequeue();
     dequeue();
     print();
}
