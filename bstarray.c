// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #define MAX_SIZE 100
// void insert(int *tree, int key, int *size) {
//     if (*size == MAX_SIZE) {
//         printf("Tree is full. Cannot insert more elements.\n");
//         return;
//     }
//     int index = 0;
//     while (tree[index] != 0) {
//         if (key < tree[index]) {
//             index = 2 * index + 1;
//         } else {
//             index = 2 * index + 2;
//         }
//     }
//     tree[index] = key;
//     (*size)++;
// }
// int search(int key, int *tree) {
//     int index = 0;
//     while (index < MAX_SIZE) {
//         if (tree[index] == key) {
//             return index;
//         } else if (key < tree[index]) {
//             index = 2 * index + 1;
//         } else {
//             index = 2 * index + 2;
//         }
//     }
//     return 0;
// }
// void inorder(int *tree, int index) {
//     if (index < MAX_SIZE && tree[index] != 0) {
//         inorder(tree, 2 * index + 1);
//         printf("%d ", tree[index]);
//         inorder(tree, 2 * index + 2);
//     }
// }
// void swap(int *a,int *b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// void maxheapify(int *arr,int n,int i){
//     int largest=i;
//     int l=2*i+1;
//     int r=2*i+2;
//     while(l<n&& arr[l] > arr[largest]){
//         largest=l;
//         }
//     while(r<n&& arr[r] > arr[largest]){
//         largest=r;
//         }
//     if(largest!=i){
//         swap(&arr[i],&arr[largest]);
//         maxheapify(arr,n,largest);
//     }
// }
// void heapsort(int *arr,int n){
//     for(int i=(n/2)-1;i>=0;i--){
//         maxheapify(arr,n,i);
//         }
//     for(int i=n;i>=1;i--){
//         swap(&arr[0], &arr[i]);
//         maxheapify(arr,n,0);
//     }
// }
// int main() {
//     int size = 0;
//     int *arr = malloc(sizeof(int) * 15);
//     insert(arr, 8, &size);
//     insert(arr, 3, &size);
//     insert(arr, 10, &size);
//     insert(arr, 1, &size);
//     insert(arr, 6, &size);
//     insert(arr, 14, &size);
//     printf("Array representation of the binary search tree: ");
//     // for (int i = 0; i < size; i++) {
//     //     if (tree[i] != 0) {
//     //         printf("%d ", tree[i]);
//     //     }
//     // }
//     // inorder(arr, 0);
//     heapsort(arr,6);
//     printf("\nSorted array using Heap Sort:\t");
//     for (int i = 0; i < size; i++) {
//         printf("%d\t", arr[i]);
//         }
//     printf("\n");

//     // printf("%d\n", search(10, arr));
//     // printf("Search 12: %s\n", search(12, arr) ? "Found" : "Not found");

//     return 0;
// }
// // void delete1(int *tree,int data){
// //     else if(tree[2*i+1]==-1 || Tree[2*i+1]==-1){
// //         if(tree[2*i+1]==1){
// //             tree[i]=tree[2*i+2];
// //         }
// //         else{
// //             tree[i]=tree[2*i+1];
// //         }
// //     }
// // }


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxheapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    while (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    while (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxheapify(arr, n, largest);
    }
}

int deleteheap(int *arr, int *n) {
    int del = arr[0];
    arr[0] = arr[--(*n)];
    maxheapify(arr, *n, 0);
    return del;
}

void minheapify(int *arr, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    while (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }

    while (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

void heapsort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minheapify(arr, n, i);
    }

    for (int i = n - 1; i >=1; i--) {
        swap(&arr[0], &arr[i]);
        minheapify(arr, i, 0);
    }
}

int main() {
    int size = 0;
    int *arr = malloc(sizeof(int) * 15);

    arr[size++] = 8;
    arr[size++] = 3;
    arr[size++] = 10;
    arr[size++] = 1;
    arr[size++] = 6;
    arr[size++] = 14;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
     printf("Heap before deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heapsort(arr, size);

    printf("Sorted array using Heap Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    int deletedValue = deleteheap(arr, &size);
    printf("Deleted element: %d\n", deletedValue);

    printf("Heap after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}
