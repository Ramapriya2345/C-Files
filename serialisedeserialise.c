#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Serialize a binary tree to a string
void serialize(struct TreeNode* root, char* result) {
    if (root == NULL) {
        strcat(result, "N ");
        return;
    }

    int length = snprintf(NULL, 0, "%d ", root->value);
    char buffer[length + 1];
    snprintf(buffer, length + 1, "%d ", root->value);
    strcat(result, buffer);

    serialize(root->left, result);
    serialize(root->right, result);
}

// Deserialize a string to a binary tree
struct TreeNode* deserialize(char** data) {
    if (**data == 'N') {
        (*data) += 2;
        return NULL;
    }

    int value;
    sscanf(*data, "%d ", &value);
    *data += strlen(*data) + 1;

    struct TreeNode* root = createNode(value);
    root->left = deserialize(data);
    root->right = deserialize(data);

    return root;
}

// Function to print the binary tree using in-order traversal
void printInOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

// Free the memory allocated for the tree nodes
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Serialize the binary tree
    char serializedTree[100] = "";
    serialize(root, serializedTree);
    printf("Serialized Tree: %s\n", serializedTree);

    // Deserialize the string and reconstruct the binary tree
    char* data = serializedTree;
    struct TreeNode* reconstructedTree = deserialize(&data);

    // Print the deserialized tree using in-order traversal
    printf("Deserialized Tree: ");
    printInOrder(reconstructedTree);
    printf("\n");

    // Free the memory allocated for the tree nodes
    freeTree(root);
    freeTree(reconstructedTree);

    return 0;
}

