#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* create() {
    struct node* newNode = malloc(sizeof(struct node));
    int data;
    printf("Enter the element(-1 for no node):");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    newNode->value = data;
    printf("Enter left child for %d\n: ", data);
    newNode->left = create();
    printf("Enter right child for %d\n: ", data);
    newNode->right = create();
    return newNode;
}

void maxPathSum(struct node* root, int *path,int pathSize, int* max) {
    if (root == NULL) {
        return;
    }

    path[pathSize] = root->value;
    pathSize++;

    if (root->left == NULL && root->right == NULL) {
        int sum = 0;
        for (int i = 0; i < pathSize; i++) {
            sum += path[i];
        }
        if (sum > *max) {
            *max = sum;
        }
    }

    maxPathSum(root->left,path, pathSize, max);
    maxPathSum(root->right, path,pathSize, max);
}

int main() {
    struct node* root = create();
    int max = -99999999;
    int path[100];
    maxPathSum(root,path, 0, &max);
    printf("Max sum: %d\n", max);

    return 0;
}

