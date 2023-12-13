#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

void findPostOrder(int inorder[], int preorder[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd)
        return;

    int root = search(inorder, inStart, inEnd, preorder[(*preIndex)++]);

    findPostOrder(inorder, preorder, inStart, root - 1, preIndex);
    findPostOrder(inorder, preorder, root + 1, inEnd, preIndex);

    printf("%d ", inorder[root]);
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int preorder[] = {3, 9, 20, 15, 7};
    int len = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    printf("Postorder traversal: ");
    findPostOrder(inorder, preorder, 0, len - 1, &preIndex);
    printf("\n");

    return 0;
}
