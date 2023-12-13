#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create(){
    struct node *newNode=malloc(sizeof(struct node));
    int data;
    printf("Enter the element(-1 for no node):");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    newNode->data=data;
    printf("Enter left child for %d\n: ",data);
    newNode->left=create();
    printf("Enter right child for %d\n: ",data);
    newNode->right=create();
    return newNode;
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void toDoublyLinked(struct node *root, struct node **head) {
    if (root == NULL) {
        return;
    }
    static struct node *prev = NULL;
    toDoublyLinked(root->left, head);
    if (prev == NULL) {
        *head = root;
    } else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    toDoublyLinked(root->right, head);
}

void printDoublyLinked(struct node *head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->right;
    }
    printf("\n");
}

int main() {
    struct node *root=NULL;
    root=create();
    printf("Binary Tree (Inorder Traversal): ");
    inorder(root);
    printf("\n");

    struct node *head = NULL;
    toDoublyLinked(root, &head);
    printDoublyLinked(head);

    return 0;
}


// Time Complexity:

// The create function prompts the user for each element in a recursive manner, building the binary tree. In the worst case, each element is visited once, so the time complexity of creating the binary tree is O(N), where N is the number of elements in the tree.
// The inorder traversal also visits each node once, resulting in an additional time complexity of O(N).
// The toDoublyLinked function has a time complexity of O(N) because it traverses each node once to convert the binary tree to a doubly linked list.
// The printDoublyLinked function has a time complexity of O(N) as well since it prints each node once in the doubly linked list.
// Therefore, the overall time complexity is O(N).

// Space Complexity:

// The space complexity is determined by the recursive call stack during the creation of the binary tree. In the worst case, the maximum depth of the recursion is equal to the height of the tree, which could be O(N) for a skewed tree. Therefore, the space complexity of the recursive call stack is O(N).
// The toDoublyLinked function uses a static variable prev to keep track of the previous node during the traversal. The space complexity of this variable is constant, O(1).
// Overall, the space complexity is dominated by the recursive call stack and is O(N) in the worst case.
// In summary:

// Time Complexity: O(N)
// Space Complexity: O(N)



