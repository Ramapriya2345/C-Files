#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
int search(struct node *root,int val){
    int i=0;
    struct Node *head=root;
    if(head==NULL){
        return;
    }
    while(head){
        if(head->data==val){
            return head;
        }
        else if(head->data>val){
            head=head->left;
        }
        else{
            head=head->right;
        }
    }
    printf("Element not found");
    return NULL;
}
struct Node *createNode(int item) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    struct Node *newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }

    struct Node *current = root;
    struct Node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            printf("Duplicate elements are not allowed in the tree.");
            free(newNode);
            return root;
        }
    }
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);

    printf("Inorder Traversal: ");
    inorder(root);
    search(8,root);
    printf("\n");
    inorder(root);
    return 0;
}

