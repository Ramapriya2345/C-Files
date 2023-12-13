#include<stdio.h>
#include<stdlib.h>
int top1=-1,top2=-1,count=0;
void push1(int*array,int size,int data){
    if(top1==size-1){
            printf("\nOverflow");
    }
    else{
        top1++;
        array[top1]=data;
    }
}
void push2(int*array,int size,int data){
    if(top2==size-1){
            printf("\nOverflow");
    }
    else{
        top2++;
        array[top2]=data;
    }
}

int pop1(int*array){
    return array[top1--];
}

int pop2(int*array){
    return array[top2--];
}

void enqueue(int data1,int*array1,int size){
    push1(array1,size,data1);
    count++;
}

void dequeue(int*array1,int*array2,int size){
    int x,y,a,b;
    if(top1==-1 && top2==-1){
        printf("\nThe queue is empty");
    }
    else{
        for(int i=0;i<count;i++){
            x=pop1(array1);
            push2(array2,size,x);
        }
        b=pop2(array2);
        printf("\nThe dequeued element is %d",b);
        count--;
        for(int j=0;j<count;j++){
            a=pop2(array2);
            push1(array1,size,a);
        }
    }
}

void printarray(int *array){
        printf("\nThe elements in the queue are:");
        for(int i=0;i<=top1;i++){
            printf("\t%d",array[i]);
        }
}

int main(){
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int *arr1=(int*)malloc(sizeof(int)*n);
    int *arr2=(int*)malloc(sizeof(int)*n);
    enqueue(10,arr1,n);
    enqueue(20,arr1,n);
    enqueue(30,arr1,n);
    dequeue(arr1,arr2,n);
    dequeue(arr1,arr2,n);

    printarray(arr1);
}