// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 5
// int stack_arr[MAX];
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
// }
// stack_arr[0]=data;
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
//     if(first==MAX-1){
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
//     printf("\n");
// }
// int main(){
// int choice,data;
// while(1){
//     printf("1.Push\n");
//     printf("2.Pop\n");
//     printf("3.Peek\n");
//     printf("4.Print\n");
//     printf("5.Exit\n");
//     printf("Enter your choice:");
//     scanf("%d",&choice);
//     switch(choice){
//         case 1:
//         printf("Enter data to be pushed:");
//         scanf("%d",&data);
//         push(data);
//         break;
//         case 2:
//         printf("Popped element is %d\n",pop());
//         break;
//         case 3:
//         printf("Top element is %d\n",peek());
//         break;
//         case 4:
//         print();
//         break;
//         case 5:
//         exit(1);
//         default:
//         printf("Wrong choice");
//     }
// }
// }
