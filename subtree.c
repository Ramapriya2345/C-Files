#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    struct node *new = malloc(sizeof(struct node));
    int data;
    printf("Enter the element (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    new->data = data;
    printf("Enter left child for %d: \n", data);
    new->left = create();
    printf("Enter right child for %d: \n", data);
    new->right = create();
    return new;
}

bool areIdentical(struct node *root1, struct node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

bool isSubtree(struct node *T, struct node *S)
{
    if (S == NULL)
    {
        return true;
    }

    if (T == NULL)
    {
        return false;
    }

    if (areIdentical(T, S))
    {
        return true;
    }

    return isSubtree(T->left, S) || isSubtree(T->right, S);
}

int main()
{
    printf("Tree: \n");
    struct node *T = create();
    printf("Subtree: \n");
    struct node *S = create();

    clock_t start = clock();

    if (isSubtree(T, S))
    {
        printf("Tree S is a subtree of tree T.\n");
    }
    else
    {
        printf("Tree S is not a subtree of tree T.\n");
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Store time taken in a file
    FILE *fp = fopen("Subtree.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fprintf(fp, "%f \n", time_taken);

    fclose(fp);

    return 0;
}
