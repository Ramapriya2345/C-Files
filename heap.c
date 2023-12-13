#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int extractmin(int *arr) {
    return arr[0];
}

void deletemin(int *arr, int *n) {
    arr[0] = arr[(*n) - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
}

void heapsort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {6, 3, 9, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before minHeapify: ");
    printArray(arr, n);

    for (int i = (n / 2) - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    printf("After minHeapify: ");
    printArray(arr, n);

    printf("\n");

    heapsort(arr, n);

    printf("Sorted array is:\n");
    printArray(arr, n);

    printf("\n");

    printf("Minimum element: %d\n", extractmin(arr));

    deletemin(arr, &n);

    printf("After deleting minimum element: ");
    printArray(arr, n);

    return 0;
}
