// #include <stdio.h>
// #include <stdlib.h>
// struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// };
// struct node *create(){
//     struct node *newNode=malloc(sizeof(struct node));
//     printf("Enter the node: ");
//     int data;
//     scanf("%d",&data);
//     newNode->data=data;
//     if(data==-1){
//         return NULL;
//     }
//     printf("Enter left node for %d:",data);
//     newNode->left=create();
//     printf("Enter right node for %d:",data);
//     newNode->right=create();
//     return newNode;
//     }
// int main(){
//     struct node *root=NULL;
//     root=create();
// }


#include <stdio.h>
#include <stdlib.h>
// int main(){
//     int n,data;
//     printf("enter no of elements:");
//     scanf("%d",&n);
//     int *arr=calloc((2^n-1),sizeof(int));
//     for(int i=0;i<n;i++){
//         printf("Enter element:");
//         scanf("%d",&data);       
//         while(*(arr+i)!=0){ 
//             if(arr[i]>data){
//                 i=2*i+1;
//             }
//             else{
//                 i=2*i+2;
//             }
//         }
//         arr[i]=data;
//     }
//     for(int i=0;i<2^n-1;i++){
//         printf("%d ",arr[i]);
//     }
// }
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *create(int *a);
void printArray(int *arr, int size);

int main(){
    int n;
    printf("Enter no of elements:");
    scanf("%d", &n);
    int size = (int)pow(2, n) - 1;
    int *arr = (int *)calloc(size, sizeof(int));
    arr = create(arr);
    printArray(arr, size);
    free(arr);
    return 0;
}

int *create(int *a){
    int i = 0;
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if(data == -1){
        return NULL;
    }
    if(i==0){
      a[i] = data;
    }   
    printf("Enter left child of %d:\n", data);
    a[2*i+1] = create(a);
    printf("Enter right child of %d:\n", data);
    a[2*i+2] = create(a);
    return a;
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
