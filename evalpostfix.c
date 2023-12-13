#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(int data){
    if(top==MAX-1){
        printf("Overflow");
        exit(1);
    }
    stack[++top]=data;
}
int pop(){
    if(top==-1){
        printf("Underflow");
        exit(1);
    }
    int val=stack[top];
    top--;
    return val;
}
int eval(int val1,int val2,char op){
 if(op=='+'){
    return val2+val1;
 }
 else if(op=='-'){
    return val2-val1;
 }
 else if(op=='*'){
    return val2*val1;
 }
 else if(op=='/'){
    return val2/val1;
 }
 else if(op=='^'){
    return val2^val1;
 }
 else{
    return 0;
 }
}
int evaluate(char *postfix){
    for(int i=0;postfix[i]!='\0';i++){
      if(isalnum(postfix[i])){
        push(postfix[i]-'0');
      }
      else{
        int val1=pop();
        int val2=pop();
        int result=eval(val1,val2,postfix[i]);
        push(result);
      }
    }
    return stack[top];
}
int main(){
    char *postfix="12+345/*-6+";
    int result=evaluate(postfix);
    printf("%d",result);
    return 0;
}

// // //linked list
// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//    int data;
//    struct node *next;
// } *stack = NULL, *head = NULL;
// void push(struct node *ptr, char data)
// {
//    struct node *head = malloc(sizeof(struct node));
//    head->data = data;
//    head->next = NULL;
//    head->next = ptr;
//    ptr = head;
// }
// int pop()
// {
//    if (!stack)
//    {
//       printf("Underflow");
//       exit(1);
//    }
//    struct node *temp = stack;
//    int val = temp->data;
//    stack = stack->next;
//    free(temp);
//    temp = NULL;
//    return val;
// }
// int eval(int val1, int val2, char op)
// {
//    if (op == '+')
//    {
//       return val2 + val1;
//    }
//    else if (op == '-')
//    {
//       return val2 - val1;
//    }
//    else if (op == '*')
//    {
//       return val2 * val1;
//    }
//    else if (op == '/')
//    {
//       return val2 / val1;
//    }
//    else if (op == '^')
//    {
//       return val2 ^ val1;
//    }
//    else
//    {
//       return 0;
//    }
// }
// void evaluate()
// {
// }
// int main()
// {
//    char *postfix = "12+345/*-6+";
//    int result = evaluate(postfix);
//    printf("%d", result);
//    return 0;
// }