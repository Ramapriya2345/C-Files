#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the index of value in the inorder array
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to construct the tree and find postorder traversal
struct Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node* node = newNode(preorder[(*preIndex)++]);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);

    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

// Main function
int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int preorder[] = {3, 9, 20, 15, 7};
    int len = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    // Construct the tree
    struct Node* root = buildTree(inorder, preorder, 0, len - 1, &preIndex);

    // Print the postorder traversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
