#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int data) {
    struct node *root1 = (struct node *)malloc(sizeof(struct node));
    if (root1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    root1->data = data;
    root1->left = NULL;
    root1->right = NULL;

    return root1; // Return the new node
}

struct node *create(struct node *root, int data) {
    if (data == -1) {
        return NULL;
    }
    if (root == NULL) {
        root = insert(root, data);
    } else {
        if (data < root->data) {
            root->left = create(root->left, data);
        } else if (data > root->data) {
            root->right = create(root->right, data);
        }
    }
    return root;
}

void inorder(struct node *root, int k, int *count) {
    if (root != NULL) {
        inorder(root->left, k, count);
        (*count)++;
        if (*count == k) {
            printf("kth smallest element: %d\n", root->data);
            return; // Stop traversal after finding the kth smallest element
        }
        inorder(root->right, k, count);
    }
}

// Function to generate DOT code for the tree
// Function to generate DOT code for the tree with dynamic inner color assignment
void generateDot(struct node *root, FILE *dotFile) {
    if (root != NULL) {
        // Example: Assign inner colors based on node values
        char* fillcolor;
        if (root->data % 2 == 0) {
            fillcolor = "lightblue";
        } else {
            fillcolor = "lightcoral";
        }

        fprintf(dotFile, "%d [label=\"%d\", color=\"blue\", fillcolor=\"%s\", style=\"filled\"];\n", root->data, root->data, fillcolor);

        if (root->left != NULL) {
            fprintf(dotFile, "%d -> %d [color="black"];\n", root->data, root->left->data);
        }
        if (root->right != NULL) {
            fprintf(dotFile, "%d -> %d [color="black"];\n", root->data, root->right->data);
        }

        generateDot(root->left, dotFile);
        generateDot(root->right, dotFile);
    }
}


int main() {
    struct node *root = NULL;
    int data;
    do {
        printf("Enter data (-1 for no node): ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        root = create(root, data);
    } while (data != -1);

    printf("Enter k to find kth smallest element: ");
    int k;
    scanf("%d", &k);

    int count = 0; // Initialize count to 0
    inorder(root, k, &count);

    // Output DOT code to a file
    FILE *dotFile = fopen("tree.dot", "w");
    if (dotFile == NULL) {
        printf("Error opening DOT file.\n");
        exit(1);
    }
    fprintf(dotFile, "digraph BST {\n");
    generateDot(root, dotFile);
    fprintf(dotFile, "}\n");
    fclose(dotFile);

    return 0;
}
