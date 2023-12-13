//array bst
//works perf
#include <stdio.h>

int tree[1000] = {0}; // Array to represent the tree structure
int size = 0;         // Size of the tree

// Function to insert a value into the binary search tree
void insert(int value, int index) {
    if (tree[index] == 0) {
        tree[index] = value;
        size++;
    } else if (value < tree[index]) {
        insert(value, 2 * index + 1); // Go left
    } else {
        insert(value, 2 * index + 2); // Go right
    }
}
// int findSuccessor(int idx) {
//     int successor = tree[(2 * idx) + 2];
//     while (tree[(2 * successor) + 1] != 0) {
//         successor = tree[(2 * successor) + 1];
//     }
//     return successor;
// }
int search(int data) {
    int idx = 0; // Start at the root
    while (tree[idx] != 0) {
        if (data == tree[idx]) {
            return idx; // Found the target value
        } else if (data < tree[idx]) {
            idx = 2 * idx + 1; // Go left
        } else {
            idx = 2 * idx + 2; // Go right
        }
    }
    return -1; // Node not found
}
void delete(int data) {
    int idx = search(data);
    if (idx == -1) {
        printf("\nNode not found");
        return;
    }
    // Node with no children or one child
    if (tree[2 * idx + 1] == 0) {
        if (tree[2 * idx + 2] == 0) {
            // Node with no children
            tree[idx] = 0;
        } else {
            // Node with one right child
            tree[idx] = tree[2 * idx + 2];
        }
    } else {
        // Node with two children
        int successorIdx = 2 * idx + 1;
        while (tree[2 * successorIdx + 2] != 0) {
            successorIdx = 2 * successorIdx + 2;
        }
        tree[idx] = tree[successorIdx];
        // Delete the successor node
        if (tree[2 * successorIdx + 1] == 0) {
            tree[successorIdx] = 0;
        } else {
            tree[successorIdx] = tree[2 * successorIdx + 1];
        }
    }
}
// left root right
int i = 0;
void inorder(int i){
    if(tree[(2 * i) + 1] != 0){                          //line 1
        inorder((2 * i) + 1);   //i=0,1 stops here
    }
    printf("%d ", tree[i]);
    if(tree[(2 * i) + 2] != 0){
        inorder((2 * i) + 2);
    }
}
void preorder(int i){
    if(tree[i] != 0){
        printf("%d ", tree[i]);
    }
    if(tree[(2 * i) + 1] != 0){                          
        preorder((2 * i) + 1);   
    }
    if(tree[(2 * i) + 2] != 0){
        preorder((2 * i) + 2);
    }
}
void postorder(int i){
    if(tree[(2 * i) + 1] != 0){                          
        postorder((2 * i) + 1);   
    }
    if(tree[(2 * i) + 2] != 0){
        postorder((2 * i) + 2);
    }
    printf("%d ", tree[i]);
}
int main() {
    insert(5, 0);
    insert(3, 0);
    insert(7, 0);
    insert(2, 0);
    insert(4, 0);
    insert(6, 0);
    insert(8, 0);
    insert(1, 0);
    printf("Inorder traversal: ");
    inorder(i);

    delete(2);
    printf("\nInorder traversal: ");
    inorder(i);

    delete(70);
    printf("\nInorder traversal: ");
    inorder(i);

    delete(1);
    printf("\nInorder traversal: ");
    inorder(i);

    return 0;
}