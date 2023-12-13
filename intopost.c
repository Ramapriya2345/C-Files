#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
    char val;
    struct node *next;
};

struct node *top = NULL;

void push(char val){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if(new == NULL){
        printf("Stack overflow\n");
        exit(0);
    }
    new->val = val;
    new->next = top;
    top = new;
}

char pop(){
    if(top == NULL) {
        printf("Stack underflow \n");
        return '\0';
    }
    struct node *temp = top;
    top = top->next;
    char value = temp->val;
    free(temp);
    return value;
}

// void print(){
//     struct node *ptr = top;
//     while(ptr != NULL){
//         printf("%c ", ptr->val);
//         ptr = ptr->next;
//     }
// }

int precedence(char i){
    if(i == '^'){
        return 3;
    }
    else if(i == '*' || i == '/'){
        return 2;
    }
    else if(i == '+' || i == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int isoperator(char i){
    if(i == '*' || i == '+' || i == '-' || i == '^' || i == '/'){
        return 1;
    }
    return 0;
}
void infixToPostfix(char *exp) {
    int i = 0;
    while(exp[i] != '\0') {
       if(exp[i] == '(') {
            push(exp[i]);
        } 
        else if(isalnum(exp[i])){
            printf("%c",exp[i]);
        }
        else if(exp[i] == ')') {
            while(top != NULL && top->val != '(') {
                printf("%c", pop());
            }
            pop();
        } else if(isoperator(exp[i])){
            while(top != NULL && precedence(exp[i]) <= precedence(top->val)) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
        i++;
    }
    while(top != NULL) {
        printf("%c", pop());
    }
}


int main(){
    char exp[100];
    printf("Enter the infix expression: ");
    gets(exp);
    printf("The postfix expression is: ");
    infixToPostfix(exp);
    return 0;
}
