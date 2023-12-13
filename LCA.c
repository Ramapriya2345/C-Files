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
struct node *findLCA(struct node *root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    struct node *leftLCA = findLCA(root->left, n1, n2);
    struct node *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
int main() {
    struct node *root = create();
    int n1, n2;

    printf("Enter the values of nodes to find their LCA: ");
    scanf("%d %d", &n1, &n2);

    struct node *lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        printf("Lowest Common Ancestor of %d and %d is %d\n", n1, n2, lca->data);
    } else {
        printf("One or both nodes not present in the tree\n");
    }

    return 0;
}


