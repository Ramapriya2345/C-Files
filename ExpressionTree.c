#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char val;
    struct node *left;
    struct node *right;
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

struct node *constructTree(char postfix[]) {
    struct node *stack[100];
    int top = -1;
    struct node *t, *t1, *t2;
    int i;
    for ( i = 0; i < strlen(postfix); i++) {
        if (!isOperator(postfix[i])) {
            t = (struct node *)malloc(sizeof(struct node));
            t->left = t->right = NULL;
            t->val = postfix[i];
            stack[++top] = t;
        } else {
            t = (struct node *)malloc(sizeof(struct node));
            t->left = t->right = NULL;
            t->val = postfix[i];
            t1 = stack[top--];
            t2 = stack[top--];
            t->right = t1;
            t->left = t2;
            stack[++top] = t;
        }
    }
    return stack[top--];
}

int evaluate(int a, int b, char op) {
    int operand1 = a;
    int operand2 = b;
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return operand1 ^ operand2;
    }
    return 0;
}

int evaluate_exp(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->val - '0';
    }
    int left = evaluate_exp(root->left);

    int right = evaluate_exp(root->right);

    return evaluate(left, right, root->val);
}

void inorder(struct node *t) {
    if (t) {
        inorder(t->left);
        printf("%c ", t->val);
        inorder(t->right);
    }
}

void preorder(struct node *t) {
    if (t) {
        printf("%c ", t->val);
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(struct node *t) {
    if (t) {
        postorder(t->left);
        postorder(t->right);
        printf("%c ", t->val);
    }
}

int main() {
    // char postfix[] = "42+34-*";
    char postfix[100];
    gets(postfix);
    struct node *root = constructTree(postfix);

    printf("Inorder Expression: ");
    inorder(root);
    printf("\n");

    printf("Preorder Expression: ");
    preorder(root);
    printf("\n");

    printf("Postorder Expression: ");
    postorder(root);
    printf("\n");

    int result = evaluate_exp(root);
    printf("Result: %d\n", result);

    return 0;
}