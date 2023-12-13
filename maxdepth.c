#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create(){
    struct node *newNode=malloc(sizeof(struct node));
    int data;
    printf("Enter the element(-1 for no node):");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    newNode->data=data;
    printf("Enter left child for %d\n: ",data);
    newNode->left=create();
    printf("Enter right child for %d\n: ",data);
    newNode->right=create();
    return newNode;
}

int maxDepth(struct node *node){
    if(node==NULL){
        return 0;
    }
    else{
        int ldepth=maxDepth(node->left);
        int rdepth=maxDepth(node->right);
        if(ldepth>rdepth){
            return(ldepth+1);
        }
        else return(rdepth+1);
    }
}
int main() {
    struct node *root=NULL;
    root=create();
   printf("THe maxdepth: %d",maxDepth(root));

    return 0;
}

