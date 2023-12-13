// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// void create(int *a, int i, int size);
// void printArray(int *arr, int size);
// int main(){
//     int n;
//     printf("Enter no of elements:");
//     scanf("%d", &n);
//     int size = pow(2, n) - 1;
//     int *arr = (int *)calloc(size, sizeof(int));
//     create(arr, 0, size);
//     printArray(arr, size);
//     free(arr);
//     return 0;
// }
// void create(int *a, int i, int size){
//     int data;
//     printf("Enter data (-1 for no node): ");
//     scanf("%d", &data);
//     if(i >= size && data != -1){
//         printf("Overflow\n");
//         printArray(a, size);
//         exit(1);
//     }
//     if(data == -1){
//         return;
//     }
//     a[i] = data;
//     printf("Enter left child of %d:\n", data);
//     create(a, 2 * i + 1, size);
//     printf("Enter right child of %d:\n", data);
//     create(a, 2 * i + 2, size);
// }
// void printArray(int *arr, int size){
//     int last = -1;
//     for(int i = size - 1; i >= 0; i--){
//         if(arr[i] != 0){
//             last = i;
//             break;
//         }
//     }
//     for(int i = 0; i <= last; i++){
//         printf("%d ", arr[i]);
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void create(int *a, int i, int size);
void printArray(int *arr, int size);
void inorder(int *arr, int i);
void preorder(int *arr, int i, int size);
void postorder(int *arr, int i, int size);

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int size = pow(2, n) - 1;
    int *arr = (int *)calloc(size, sizeof(int));
    create(arr, 0, size);
    printf("Inorder traversal: ");
    inorder(arr, 0);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(arr, 0, size);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(arr, 0, size);
    printf("\n");
    free(arr);
    return 0;
}

void create(int *a, int i, int size)
{
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (i >= size && data != -1)
    {
        printf("Overflow\n");
        printArray(a, size);
        exit(1);
    }
    if (data == -1)
    {
        return;
    }
    a[i] = data;
    printf("Enter left child of %d:\n", data);
    create(a, 2 * i + 1, size);
    printf("Enter right child of %d:\n", data);
    create(a, 2 * i + 2, size);
}

void printArray(int *arr, int size)
{
    int last = -1;
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            last = i;
            break;
        }
    }
    for (int i = 0; i <= last; i++)
    {
        printf("%d ", arr[i]);
    }
}

// void inorder(int *arr, int i, int size) {
//     if (i >= size || arr[i] == 0) {
//         return;
//     }
//     inorder(arr, 2 * i + 1, size);
//     printf("%d ", arr[i]);
//     inorder(arr, 2 * i + 2, size);
// }

void inorder(int *arr, int i)
{
    if (arr[2 * i + 1] != -1)
    {
        inorder(arr, 2 * i + 1);
    }
    printf("%d ", arr[i]);
    if (arr[2 * i + 2] != -1)
    {
        inorder(arr, 2 * i + 2);
    }
}

void preorder(int *arr, int i, int size)
{
    if (i >= size || arr[i] == 0)
    {
        return;
    }
    printf("%d ", arr[i]);
    preorder(arr, 2 * i + 1, size);
    preorder(arr, 2 * i + 2, size);
}

void postorder(int *arr, int i, int size)
{
    if (i >= size || arr[i] == 0)
    {
        return;
    }
    postorder(arr, 2 * i + 1, size);
    postorder(arr, 2 * i + 2, size);
    printf("%d ", arr[i]);
}
