// #include <stdio.h>
// #include <stdlib.h>
// struct node{
//     int data;
//     struct node *left,*right;
// }*root=NULL;
// struct node *create(){
//     struct node *newNode=malloc(sizeof(struct node));
//     int data;
//     printf("Enter the element(-1 for no node):");
//     scanf("%d",&data);
//     if(data==-1){
//         return NULL;
//     }
//     newNode->data=data;
//     printf("Enter left child for %d\n: ",data);
//     newNode->left=create();
//     printf("Enter right child for %d\n: ",data);
//     newNode->right=create();
//     return newNode;
// }
// void print(struct node *root){
//         if (root != NULL) {
//         print(root->left);
//         printf("%d -> ", root->data);
//         print(root->right);
//     }
// }
// int main(){
//     root=create();
//     print(root);
// }



#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the Binary Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new Node
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Iterative Inorder Traversal of the Binary Tree
void iterativeInorder(struct Node *root) {
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Iterative Preorder Traversal of the Binary Tree
void iterativePreorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node *current = stack[top--];
        printf("%d ", current->data);
        if (current->right) {
            stack[++top] = current->right;
        }
        if (current->left) {
            stack[++top] = current->left;
        }
    }
}

// Iterative Postorder Traversal of the Binary Tree
void iterativePostorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Node *stack1[100];
    struct Node *stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node *current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left) {
            stack1[++top1] = current->left;
        }
        if (current->right) {
            stack1[++top1] = current->right;
        }
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Example usage of the functions
int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Iterative Inorder traversal: ");
    iterativeInorder(root);
    printf("\n");

    printf("Iterative Preorder traversal: ");
    iterativePreorder(root);
    printf("\n");

    printf("Iterative Postorder traversal: ");
    iterativePostorder(root);
    printf("\n");

    return 0;
}
