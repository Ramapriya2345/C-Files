#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
}*root=NULL;
struct node *insert(struct node *root,int data){
   struct node *root1 = (struct node *)malloc(sizeof(struct node));
        if (root1 == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        root1->data = data;
        root1->left = NULL;
        root1->right = NULL;
}
struct node *create(struct node *root, int data) {
    if (data == -1) {
        return NULL;
    }
    if (root == NULL) {
        root = insert(root,data);
    } else {
        if (data < root->data) {
            root->left = create(root->left, data);
        } else if (data > root->data) {
            root->right = create(root->right, data);
        }
    }
    return root;
}
char *search(struct node *root,int key){
    while(root){
        if(key==root->data){
            return "found";
        }
        else if(key>root->data){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return "Not found";
}
// struct node* search(struct node* root, int key) {
//     if (root == NULL || root->data == key) {
//         return root;
//     }
//         return search(root->right, key);
//     }
//     return search(root->left, key);
// }
void leafnodes(struct node *root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        printf("%d ",root->data);
    }
    leafnodes(root->left);
    leafnodes(root->right);

}
void ancestor(struct node *root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL || root->right!=NULL){
        printf("%d ",root->data);
    }
    ancestor(root->left);
    ancestor(root->right);
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
    }
}
void swap(struct node *root){
    struct node *temp=root->left;
    root->left=root->right;
    root->right=temp;
}
void mirror(struct node *root){
    if(root==NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root);
}
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // struct node *temp = inorderpredecessor(root);
        // root->data = temp->data;
        // root->left = deleteNode(root->left, temp->data);
        struct node *temp = inordersuccessor(root);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct node *inorderpredecessor(struct node *root){
       struct node *temp = root->left;
       while(temp->right!=NULL){
              temp = temp->right;
       }
       return temp;
}
struct node *inordersuccessor(struct node *root){
       struct node *temp = root->right;
       while(temp->left!=NULL){
              temp = temp->left;
       }
       return temp;
}
struct node* inorderprede(struct node* root, int key) {
    struct node* pre = NULL;
    while (root) {
        if (key > root->data) {
            pre = root;
            root = root->right;
        } else if (key < root->data) {
            root = root->left;
        } else {
            if (root->left != NULL) {
                pre = root->left;
                while (pre->right)
                    pre = pre->right;
            }
            break;
        }
    }
    return pre;
}
struct node* inordersucc(struct node* root, int key) {
    struct node* succ = NULL;
    while (root) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        } else if (key > root->data) {
            root = root->right;
        } else {
            if (root->right != NULL) {
                succ = root->right;
                while (succ->left)
                    succ = succ->left;
            }
            break;
        }
    }
    return succ;
}



int main(){
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);
    root = deleteNode(root, val);
    struct node *prede=malloc(sizeof(struct node));
    printf("Enter value to find predecessor: ");
    int val1;
    scanf("%d", &val1);
    prede=inorderprede(root,val1);
    printf("inorder predecessor is %d\n",prede->data);
    struct node *succe=malloc(sizeof(struct node));
    printf("Enter value to find successor: ");
    int val2;
    scanf("%d", &val2);
    succe=inordersucc(root,val2);
    printf("inorder successor is %d\n",succe->data);
    printf("inorder:\n");
    inorder(root);
    printf("\n");
    printf("preorder:\n");
    preorder(root);
    printf("\n");
    printf("postorder:\n");
    postorder(root);
    printf("\n");
    leafnodes(root);
    printf("\n");
    ancestor(root);
    printf("\n");
    printf("The key value is %s ",search(root,10));
    printf("\n");
    mirror(root);
    printf("inorder:\n");
    inorder(root);
    printf("\n");
    printf("preorder:\n");
    preorder(root);
    printf("\n");
    printf("postorder:\n");
    postorder(root);
    printf("\n");
    leafnodes(root);
    printf("\n");
    ancestor(root);
    printf("\n");
    free(root);

    return 0;
}




#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if two trees are mirror images
int areMirrors(struct TreeNode* root1, struct TreeNode* root2) {
    // If both trees are empty, they are mirrors
    if (root1 == NULL && root2 == NULL)
        return 1;

    // If one of the trees is empty and the other is not, they are not mirrors
    if (root1 == NULL || root2 == NULL)
        return 0;

    // Check if the current nodes have the same value and
    // the subtrees are mirrors of each other
    return (root1->data == root2->data) &&
           areMirrors(root1->left, root2->right) &&
           areMirrors(root1->right, root2->left);
}

// Example usage
int main() {
    // Construct two sample trees
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->left = newNode(5);
    root2->right->right = newNode(4);

    // Check if the trees are mirrors
    if (areMirrors(root1, root2))
        printf("The trees are mirrors.\n");
    else
        printf("The trees are not mirrors.\n");

    return 0;
}
