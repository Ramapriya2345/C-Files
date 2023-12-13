#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
struct node {
    int data;
    struct node *left, *right;
};

struct node *create() {
    struct node *newNode = malloc(sizeof(struct node));
    int data;
    printf("Enter the element(-1 for no node):");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    newNode->data = data;
    printf("Enter left child for %d\n: ", data);
    newNode->left = create();
    printf("Enter right child for %d\n: ", data);
    newNode->right = create();
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct node *node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
}
int diameter(struct node *root){
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);
    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
int main() {
    struct node *root = NULL;
    root = create();
    printf("The diameter: %d", diameter(root));
    return 0;
}


