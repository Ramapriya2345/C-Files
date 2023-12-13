// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #define MAX 100
// char stack[MAX];
// int top = -1;
// char postfix[MAX];
// void push(char data);
// int pop();
// void print();
// void push(char data)
// {
//     if (top == MAX - 1)
//     {
//         printf("Overflow");
//         exit(1);
//     }
//     stack[++top] = data;
// }
// int pop()
// {
//     if (top == -1)
//     {
//         printf("Underflow");
//         exit(1);
//     }
//     // int val=stack[top--];
//     // return val;
//     top--;
// }
// void print()
// {
//     int i;
//     if (top == -1)
//     {
//         printf("Stack Underflow\n");
//         return;
//     }
//     for (i = top; i >= 0; i--)
//     {
//         printf("%d ", stack[i]);
//     }
//     printf("\n");
// }
// int precedence(char i)
// {
//     if (i == '^')
//     {
//         return 3;
//     }
//     else if (i == '*' || i == '/')
//     {
//         return 2;
//     }
//     else if (i == '+' || i == '-')
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int isoperator(char i)
// {
//     if (i == '*' || i == '+' || i == '-' || i == '^' || i == '/')
//     {
//         return 1;
//     }
//     return 0;
// }
// void infixtopostfix(char *infix)
// {
//     int i, j;
//     j = 0;
//     for (i = 0; infix[i] != '\0'; i++)
//     {
//         if (infix[i] == '(')
//         {
//             push(infix[i]);
//         }
//         else if (isalnum(infix[i]))
//         {
//             postfix[j++] = infix[i];
//         }
//         else if (infix[i] == ')')
//         {
//             while (top >= 0 && stack[top] != '(')
//             {
//                 postfix[j++] = stack[top--];
//             }
//             pop();
//         }
//         else if (isoperator(infix[i]))
//         {
//             while (top >= 0 && precedence(infix[i]) <= precedence(stack[top]))
//             {
//                 postfix[j++] = stack[top--];
//             }
//             push(infix[i]);
//         }
//     }
//     while (top >= 0)
//     {
//         postfix[j++] = stack[top--];
//     }
//     postfix[j] == '\0';
// }
// int main()
// {
//     char infix[] = "((A + B) - C * (D / E)) + F";
//     infixtopostfix(infix);
//     printf("%s", postfix);
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<ctype.h>
// #define MAX 100
// char stack[MAX];
// char postfix[MAX];
// int top=-1;
// void push(char data){
//     if(top==MAX-1){
//         printf("Overflow");
//         exit(1);
//     }
//     stack[++top]=data;
// }
// int pop(){
//     if(top==-1){
//         printf("Underflow");
//         exit(1);
//     }
//     return stack[top--];
// }
// int precedence(char i){
//     if(i=='^'){
//         return 3;
//     }
//     else if(i=='*' || i=='/'){
//         return 2;
//     }
//     else if(i=='+' || i=='-'){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int isoperator(char i){
//     if(i=='*'|| i=='+'||i=='-'||i=='^'||i=='/'){
//         return 1;
//     }
//     return 0;
// }
// void infixtopostfix(char *infix){
//     int i,j;
//     j=0;
//     for(int i=0;infix[i]!='\0';i++){
//         if(infix[i]=='('){
//             push(infix[i]);
//         }
//         else if(isalnum(infix[i])){
//             postfix[j++]=infix[i];
//         }
//         else if(infix[i]==')'){
//             while(top>=0 && stack[top]!='('){
//                 postfix[j++]=pop();
//             }
//             pop();
//         }
//         else if(isoperator(infix[i])){
//             while(top>=0 && precedence(infix[i])<=precedence(stack[top])){
//                 postfix[j++]=pop();
//             }
//             push(infix[i]);
//         }
//     }
//     while (top>=0)
//     {
//      postfix[j++]=stack[top--];
//     }
//     postfix[j]='\0';
// }
// int main(){
//     char infix[]="((A + B) - C * (D / E)) + F";
//     infixtopostfix(infix);
//     printf("%s",postfix);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #define MAX 100

// void push(char data, char *stack, int *top);
// int pop(char *stack, int *top);
// void print(char *stack, int top);
// int precedence(char i);
// int isoperator(char i);
// void infixtopostfix(char *infix, char *postfix);

// int main()
// {
//     char stack[MAX];
//     char postfix[MAX];
//     int top = -1;
//     char infix[] = "((A + B) - C * (D / E)) + F";
//     infixtopostfix(infix, postfix);
//     printf("%s", postfix);
//     return 0;
// }

// void push(char data, char *stack, int *top)
// {
//     if (*top == MAX - 1)
//     {
//         printf("Overflow");
//         exit(1);
//     }
//     stack[++(*top)] = data;
// }

// int pop(char *stack, int *top)
// {
//     if (*top == -1)
//     {
//         printf("Underflow");
//         exit(1);
//     }
//     // int val=stack[*top--];
//     // return val;
//     (*top)--;
// }

// void print(char *stack, int top)
// {
//     int i;
//     if (top == -1)
//     {
//         printf("Stack Underflow\n");
//         return;
//     }
//     for (i = top; i >= 0; i--)
//     {
//         printf("%c ", stack[i]);
//     }
//     printf("\n");
// }

// int precedence(char i)
// {
//     if (i == '^')
//     {
//         return 3;
//     }
//     else if (i == '*' || i == '/')
//     {
//         return 2;
//     }
//     else if (i == '+' || i == '-')
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isoperator(char i)
// {
//     if (i == '*' || i == '+' || i == '-' || i == '^' || i == '/')
//     {
//         return 1;
//     }
//     return 0;
// }

// void infixtopostfix(char *infix, char *postfix)
// {
//     char stack[MAX];
//     int top = -1;
//     int i, j;
//     j = 0;
//     for (i = 0; infix[i] != '\0'; i++)
//     {
//         if (infix[i] == '(')
//         {
//             push(infix[i], stack, &top);
//         }
//         else if (isalnum(infix[i]))
//         {
//             postfix[j++] = infix[i];
//         }
//         else if (infix[i] == ')')
//         {
//             while (top >= 0 && stack[top] != '(')
//             {
//                 postfix[j++] = stack[top--];
//             }
//             pop(stack, &top);
//         }
//         else if (isoperator(infix[i]))
//         {
//             while (top >= 0 && precedence(infix[i]) <= precedence(stack[top]))
//             {
//                 postfix[j++] = stack[top--];
//             }
//             push(infix[i], stack, &top);
//         }
//     }
//     while (top >= 0)
//     {
//         postfix[j++] = stack[top--];
//     }
//     postfix[j] = '\0';
// }

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Utility function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Utility function to get the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1)
        return -1; // Stack underflow
    return stack->array[stack->top--];
}

// Function to peek at the top element of the stack without popping
int peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to convert infix expression to postfix
char* infixToPostfix(const char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    char* postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // If the current character is a digit, copy it to postfix
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Add space to separate digits
        } else if (infix[i] == '(') {
            // If the current character is '(', push it onto the stack
            push(stack, infix[i++]);
        } else if (infix[i] == ')') {
            // If the current character is ')', pop and output from the stack until '(' is encountered
            while (peek(stack) != '(') {
                postfix[j++] = pop(stack);
                postfix[j++] = ' '; // Add space to separate operators
            }
            pop(stack); // Pop '(' from the stack
            i++;
        } else if (isOperator(infix[i])) {
            // If the current character is an operator, pop and output from the stack
            // until an operator with lower precedence or '(' is encountered
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' '; // Add space to separate operators
            }
            push(stack, infix[i++]);
        } else {
            // If the current character is an operand, copy it to postfix
            postfix[j++] = infix[i++];
        }
    }

    // Pop any remaining operators from the stack and append them to postfix
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
        postfix[j++] = ' '; // Add space to separate operators
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            // If the current character is a digit, push its integer value onto the stack
            int operand = 0;
            while (isdigit(postfix[i])) {
                operand = operand * 10 + (postfix[i] - '0');
                i++;
            }
            push(stack, operand);
        } else if (postfix[i] != ' ') {
            // If the current character is an operator, pop two operands from the stack,
            // apply the operator, and push the result back onto the stack
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
            i++;
        } else {
            i++; // Skip space
        }
    }

    // The final result is at the top of the stack
    int result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

// Example usage
int main() {
    const char* infixExpression = "3 + 12 / ( 2 * 6 )";
    
    // Convert infix to postfix
    char* postfixExpression = infixToPostfix(infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);
    
    // Evaluate postfix expression
    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    free(postfixExpression);

    return 0;
}                                                                                                                                                                                                                                                                                                               

