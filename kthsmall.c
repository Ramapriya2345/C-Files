// // #include <stdio.h>
// // #include <stdlib.h>

// // struct node {
// //     int data;
// //     struct node *left, *right;
// // };

// // struct node *insert(struct node *root, int data) {
// //     struct node *root1 = (struct node *)malloc(sizeof(struct node));
// //     if (root1 == NULL) {
// //         printf("Memory allocation failed.\n");
// //         exit(1);
// //     }
// //     root1->data = data;
// //     root1->left = NULL;
// //     root1->right = NULL;

// //     return root1; // Return the new node
// // }

// // struct node *create(struct node *root, int data) {
// //     if (data == -1) {
// //         return NULL;
// //     }
// //     if (root == NULL) {
// //         root = insert(root, data);
// //     } else {
// //         if (data < root->data) {
// //             root->left = create(root->left, data);
// //         } else if (data > root->data) {
// //             root->right = create(root->right, data);
// //         }
// //     }
// //     return root;
// // }

// // void inorder(struct node *root, int k, int *count,int total) {
// //     if (root != NULL) {
// //         inorder(root->left, k, count,total);
// //         (*count)++;
// //         if(k>total){
// //             printf("Invalid k value");
// //             return;
// //         }
// //         if (*count == k) {
// //             printf("kth smallest element: %d\n", root->data);
// //             return;
// //         }
// //         inorder(root->right, k, count,total);
// //     }
// // }

// // int main() {
// //     struct node *root = NULL;
// //     int data,total=0;
// //     do {
// //         printf("Enter data (-1 for no node): ");
// //         scanf("%d", &data);
// //         total++;
// //         if (data == -1) {
// //             break;
// //         }
// //         root = create(root, data);
// //     } while (data != -1);
// //     printf("Enter k to find kth smallest element: ");
// //     int k;
// //     scanf("%d", &k);

// //     int count = 0;
// //     inorder(root, k, &count,total-1);

// //     return 0;
// // }

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <limits.h>

// #define MAX_SIZE INT_MAX

// void insert(int *tree, int key, int *size)
// {
//     if (*size == MAX_SIZE)
//     {
//         printf("Tree is full. Cannot insert more elements.\n");
//         return;
//     }

//     int index = 0;
//     while (tree[index] != 0)
//     {
//         if (key < tree[index])
//         {
//             index = 2 * index + 1;
//         }
//         else
//         {
//             index = 2 * index + 2;
//         }
//     }

//     tree[index] = key;
//     (*size)++;
// }

// void inorder(int *tree, int index, int k, int *count, int size)
// {
//     if (index < size && tree[index] != 0)
//     {
//         inorder(tree, 2 * index + 1, k, count, size);
//         (*count)++;
//         if (k > size)
//         {
//             printf("Invalid k value\n");
//             return;
//         }
//         if (*count == k)
//         {
//             printf("The kth smallest element: %d\n", tree[index]);
//             return;
//         }
//         inorder(tree, 2 * index + 2, k, count, size);
//     }
// }

// int main()
// {
//     int size = 0;
//     int data;
//     int *arr = malloc(sizeof(int) * MAX_SIZE);
//     printf("Enter values (enter -1 to stop): ");
//     do
//     {
//         scanf("%d", &data);
//         if (data != -1)
//         {
//             insert(arr, data, &size);
//         }
//     } while (data != -1);

//     int k;
//     printf("Enter the value of k: ");
//     scanf("%d", &k);

//     int count = 0;
//     inorder(arr, 0, k, &count, size);

//     free(arr);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void inorder(struct node *root, int k, int *count, int total) {
    if (root != NULL) {
        inorder(root->left, k, count, total);
        (*count)++;
        if (k > total) {
            printf("Invalid k value");
            return;
        }
        if (*count == k) {
            printf("kth smallest element: %d\n", root->data);
            return;
        }
        inorder(root->right, k, count, total);
    }
}

int main() {
    struct node *root = NULL;
    int data, total = 0;
    srand(time(NULL));

    do {
        data = rand() % 1000000000000; // Adjust the range of random values as needed
        total++;
        if (total > 1000000000) { // Limit the number of nodes for simplicity
            break;
        }
        root = create(root, data);
    } while (data != -1);

    // printf("Enter k to find kth smallest element: ");
    // int k;
    // scanf("%d", &k);

    int count = 0;
    clock_t start = clock();

    inorder(root,  678123958, &count, total - 1);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Store time taken in a file
    FILE *fp = fopen("Kthsmallest.txt", "a");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(fp, " %f \n", time_taken);

    fclose(fp);

    return 0;
}
