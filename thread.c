#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
    int lthread, rthread;
};

struct node* leftMost(struct node *n) {
    if (n == NULL)
        return NULL;

    while (n->left != NULL)
        n = n->left;
    return n;
}

void inorder(struct node* root) {
    struct node *cur = leftMost(root);
    while (cur != NULL) {
        printf("%d ", cur->data);
        if (cur->rthread)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    node->lthread = node->rthread = 0;
    return node;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) return newNode(key);

    if (key < root->data) {
        struct node* lchild = root->left;
        if (lchild == NULL) {
            root->left = newNode(key);
            root->lthread = 1;
        } else {
            insert(lchild, key);
        }
    } else if (key > root->data) {
        struct node* rchild = root->right;
        if (rchild == NULL) {
            root->right = newNode(key);
            root->rthread = 1;
        } else {
            insert(rchild, key);
        }
    }

    return root;
}

int main() {
    struct node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 16);

    printf("Inorder traversal of the given tree\n");
    inorder(root);
    printf("\n");

    return 0;
}

