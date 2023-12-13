// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *left, *right;
// };

// struct node *insert(struct node *root, int data)
// {
//     struct node *root1 = (struct node *)malloc(sizeof(struct node));
//     if (root1 == NULL)
//     {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     root1->data = data;
//     root1->left = NULL;
//     root1->right = NULL;

//     return root1;
// }

// struct node *create(struct node *root, int data)
// {
//     if (data == -1)
//     {
//         return NULL;
//     }
//     if (root == NULL)
//     {
//         root = insert(root, data);
//     }
//     else
//     {
//         if (data < root->data)
//         {
//             root->left = create(root->left, data);
//         }
//         else if (data > root->data)
//         {
//             root->right = create(root->right, data);
//         }
//     }
//     return root;
// }
// void toGST(struct node *root)
// {
//     static int sum = 0;
//     if (root == NULL)
//     {
//         return;
//     }
//     toGST(root->right);
//     int copy = root->data;
//     root->data = sum;
//     sum += copy;
//     toGST(root->left);
// }
// void inorder(struct node *root)
// {
//     if (root != NULL)
//     {
//         inorder(root->left);
//         printf("%d-> ", root->data);
//         inorder(root->right);
//     }
// }

// int main()
// {
//     struct node *root = NULL;
//     int data;
//     do
//     {
//         printf("Enter data (-1 for no node): ");
//         scanf("%d", &data);
//         if (data == -1)
//         {
//             break;
//         }
//         root = create(root, data);
//     } while (data != -1);
//     inorder(root);
//     printf("\n");
//     toGST(root);
//     inorder(root);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insert(int *tree, int key, int *size) {
    if (*size == MAX_SIZE) {
        printf("Tree is full. Cannot insert more elements.\n");
        return;
    }

    int index = 0;

    while (tree[index] != 0) {
        if (key < tree[index]) {
            index = 2 * index + 1;
        } else {
            index = 2 * index + 2;
        }
    }

    tree[index] = key;
    (*size)++;
}

void toGST(int *arr, int n, int *sum, int index) {
    if (index < n && arr[index] != 0) {
        toGST(arr, n, sum, 2 * index + 2);
        *sum += arr[index-1];
        arr[index] = *sum;

        toGST(arr, n, sum, 2 * index + 1);
    }
}

void inorder(int *tree, int index) {
    if (index < MAX_SIZE && tree[index] != 0) {
        inorder(tree, 2 * index + 1);
        printf("%d ", tree[index]);
        inorder(tree, 2 * index + 2);
    }
}

int main() {
    int size = 0;
    int data;
    int sum=0;
    int i=0;
    int *arr = malloc(sizeof(int) * MAX_SIZE);

    printf("Enter integers to insert into the tree. Enter -1 to stop:\n");

    while (1) {
        printf("Enter an integer: ");
        scanf("%d", &data);
        i++;
        if (data == -1) {
            break;
        }

        insert(arr, data, &size);
    }

    printf("Inorder traversal of the tree:\n");
    inorder(arr, 0);
    printf("\n");
    toGST(arr,i,&sum,0);
    inorder(arr,0);
    printf("%d",0);
    free(arr);

    return 0;
}
