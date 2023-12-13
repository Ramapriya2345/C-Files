#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node *create() {
    struct node *newNode = malloc(sizeof(struct node));
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

void findPaths(struct node* root, int targetSum, int* path, int pathLength) {
    if (root == NULL) {
        return;
    }

    // Add the current node's value to the path
    path[pathLength] = root->value;
    pathLength++;

    // Check if the current node is a leaf and the path has the target sum
    if (root->left == NULL && root->right == NULL) {
        int sum = 0;
        for (int i = 0; i < pathLength; i++) {
            sum += path[i];
        }
        if (sum == targetSum) {
            // Print the path
            printf("Path: ");
            for (int i = 0; i < pathLength; i++) {
                printf("%d ", path[i]);
            }
            printf("\n");
        }
    }

    // Recursively search the left and right subtrees
    findPaths(root->left, targetSum, path, pathLength);
    findPaths(root->right, targetSum, path, pathLength);
}

int main() {
    // Create a sample binary tree
    struct node* root = create();

    int targetSum = 18;
    int path[100];  // Assuming the maximum path length is 100

    // Find and print all paths with the given sum
    findPaths(root, targetSum, path, 0);

    return 0;
}

