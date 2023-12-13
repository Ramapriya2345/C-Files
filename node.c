#include <stdio.h>
#include <stdlib.h>

// struct node {
//     int data;
//     struct node* next;
// };
// void print_list(struct node *head);
// struct node* getnode(int data) {
//     struct node* p = (struct node*)malloc(sizeof(struct node));
//     p->data=data;
//     p->next=NULL;
//     return p;
// }

// int main() {
//     struct node* start = (struct node*)malloc(sizeof(struct node));
//     struct node* p1, * p2,*p3;
//     p1=getnode(1);
//     p2=getnode(13);
//     p3=getnode(5);
//     p1->data=100;
//     p1->next=p2;
//     p2->next=p3;
//     start=p1;
//     // printf("%d\n",p1);
//     // printf("%d\n", p1->data);
//     // printf("%d\n",p1->next);
//     // printf("%d\n",p2);
//     // printf("%d\n", p2->data);
//     // printf("%d\n",p2->next);
//     // printf("%d\n",p3);
//     // printf("%d\n", p3->data);
//     // printf("%d\n",p3->next);
//     printf("%d\n",start->data);
//     printf("%d\n",start->next->data);
//     printf("%d\n",start->next->next->data);
//     print_list(start);
//     free(p1);
//     free(p2);

//     return 0;
// }
// void print_list(struct node *head)
// {
//     struct node *ptr=head;
//     while (ptr != NULL)
//     {
//         printf("%d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

//insert n nodes in a nexted list ..always as the 1st node of the nexted list
// struct node{
//     int data;
//     struct node *next;
// }*start=NULL;
// void print_list(struct node *head);
// struct node* getnode(int data);
// struct node* getnode(int data){
//     struct node *p=(struct node*)malloc(sizeof(struct node));
//     p->data=data;
//     p->next=NULL;
// }
// int main(){
//  struct node *p1=(struct node*)malloc(sizeof(struct node));
//  p1=start;
// //  struct node *p2=(struct node*)malloc(sizeof(struct node));
//  int n;
//  printf("Enter no of nodes:");
//  scanf("%d",&n);
//  int data;
//  for(int i=0 ;i<n;i++ ){
//     scanf("%d",&data);
//     p1=getnode(data);
//     p1->next=start;
//     start=p1;
// }
// print_list(start);
// }
// void print_list(struct node *head)
// {
//     struct node *ptr=head;
//     while (ptr != NULL)
//     {
//         printf("%d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// // insert at end
// struct node{
//     int data;
//     struct node *next;
// }*start=NULL;
// void insert_at_end(struct node *head,int data);
// void print_list(struct node *head);
// struct node* getnode(int data);
// struct node* getnode(int data){
//     struct node *p=(struct node*)malloc(sizeof(struct node));
//     p->data=data;
//     p->next=NULL;
// }
// int main(){
//  struct node *p1=(struct node*)malloc(sizeof(struct node));
//  p1=start;
// //  struct node *p2=(struct node*)malloc(sizeof(struct node));
//  int n;
//  printf("Enter no of nodes:");
//  scanf("%d",&n);
//  int data;
//  for(int i=0 ;i<n;i++ ){
//     scanf("%d",&data);
//     p1=getnode(data);
//     p1->next=start;
//     start=p1;
// }
// insert_at_end(start,45);
// print_list(start);
// }
// void insert_at_end(struct node *head, int data)
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->next = NULL;
//     while (head->next != NULL)
//     {
//         head= head->next;
//     }//time complexity O(n)
//     head->next = temp;
// }

// //function to print the list
// void print_list(struct node *head)
// {
//     struct node *ptr;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node* next;
// } * start = NULL;

// struct node* getnode(int data) {
//     struct node* p = (struct node*)malloc(sizeof(struct node));
//     p->data = data;
//     p->next = NULL;
//     return p;
// }

// void insert_at_end(struct node** head, int data) {
//     struct node* temp;
//     temp = (struct node*)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->next = NULL;

//     if (*head == NULL) {
//         *head = temp;
//         return;
//     }

//     struct node* current = *head;
//     while (current->next != NULL) {
//         current = current->next;
//     }

//     current->next = temp;
// }

// void print_list(struct node* head) {
//     struct node* ptr;
//     ptr = head;
//     while (ptr != NULL) {
//         printf("%d", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("\n");
// }

// int main() {
//     int n;
//     printf("Enter no of nodes: ");
//     scanf("%d", &n);
//     int data;
    
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &data);
//         insert_at_end(&start, data);
//     }

//     insert_at_end(&start, 45);
//     print_list(start);

//     return 0;
// }


// 1.function..insert at beginning..pass address of the node to be inserted..call the node as to insert(pointer to the node we r trying to insert)and start pointer & always getnode func
// 2.insert at end..func..start pointer as 1st parameter
// 3.insert n nodes at beginning..
// 4.insert n nodes at end..these 2 functions must call insert at begin & end
// 5.search(start pointer,search value)...return pointer to that node
// 6.display..print all the data part &address part 
// 7.insert after node x 
// 8.insert before node x 

//program to insert n nodes from the beginning
// #include <stdio.h>
// #include <stdlib.h>
// struct node{
//     int data;
//     struct node *next;
// }*start=NULL;
// struct node insert_at_beginning(struct node *p,int num);
// void print_list(struct node* ptr);
// struct node* getnode(int data);
// struct node insert_at_beginning(struct node *p,int num){
//     struct node *temp=malloc(sizeof(struct node));
//     temp->data=num;
//     temp->next=NULL;
//     temp->next=p;
// }
// struct node* getnode(int data) {
//     struct node* p = (struct node*)malloc(sizeof(struct node));
//     p->data=data;
//     p->next=NULL;
//     return p;
// }
// int main(){
//     struct node *head=malloc(sizeof(struct node));
//     head=getnode(23);
//     int num;
    // printf("Enter no of elements to be inserted at the beginning:");
    // scanf("%d",&num);
    // int arr[num];
    // printf("Enter the values");
    // for(int i=0;i<num;i++){
    //    scanf("%d",&arr[i]);
    //    head = insert_at_beginning(head,arr[i]);
    // }
    // print_list(head);
// }
// void print_list(struct node* ptr) {
//     struct node* ptr1;
//     ptr1 = ptr;
//     while (ptr1 != NULL) {
//         printf("%d", ptr1->data);
//         ptr1 = ptr1->next;
//     }
//     printf("\n");
// }

//delete 1st node
// #include <stdio.h>
// #include <stdlib.h>
// struct node {
//     int data;
//     struct node *link;
// };
// int main() {
//     struct node *curr = malloc(sizeof(struct node));
//     struct node *head = curr;
//     int a[] = {1, 2, 3};   
//     for (int i = 0; i < 3; i++) {
//         curr->data = a[i];
//         if (i < 2) {
//             curr->link = malloc(sizeof(struct node));
//             curr = curr->link; 
//         } else {
//             curr->link = NULL;
//         }
//     } 
//     head = head->link;
//     curr = head;
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
// }

//deleting last

// #include <stdio.h>
// #include <stdlib.h>
// struct node {
//     int data;
//     struct node *link;
// };
// int main() {
//     struct node *curr = malloc(sizeof(struct node));
//     struct node *head = curr; 
//     int a[] = {1, 2, 3,4,5};   
//     for (int i = 0; i < 5; i++) {
//         curr->data = a[i];
//         if (i < 3) {
//             curr->link = malloc(sizeof(struct node));
//             curr = curr->link;
//         } else if(i==3){
//             curr->link = NULL; 
//             break;
//         }
//     } 
//     curr = head;
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
// }

// deleting at any position
// #include <stdio.h>
// #include <stdlib.h>
// struct node {
//     int data;
//     struct node* next;
// } *start = NULL;
// void del_atany_pos(struct node** head, int pos);
// void insert_at_end(struct node** head, int data);
// struct node* getnode(int data);
// void print_list(struct node* head);
// struct node* getnode(int data) {
//     struct node* p = (struct node*)malloc(sizeof(struct node));
//     p->data = data;
//     p->next = NULL;
//     return p;
// }
// void insert_at_end(struct node** head, int data) {
//     struct node* temp;
//     temp = (struct node*)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->next = NULL;

//     if (*head == NULL) {
//         *head = temp;
//         return;
//     }

//     struct node* current = *head;
//     while (current->next != NULL) {
//         current = current->next;
//     }

//     current->next = temp;
// }
// void del_atany_pos(struct node** head, int pos) {
//     if (*head == NULL) {
//         return; // List is empty, nothing to delete.
//     }

//     if (pos == 0) {
//         struct node* temp = *head;
//         *head = (*head)->next;
//         free(temp);
//         return;
//     }
//     struct node* current = *head;
//     int count = 1;
//     while (count < pos-1 && current->next != NULL) {
//         current = current->next;
//         count++;
//     }
//     if (current->next == NULL) {
//         return; // Position is greater than the number of nodes in the list.
//     }
//     struct node* temp = current->next;
//     current->next = temp->next;
//     free(temp);
// }

// void print_list(struct node* head) {
//     struct node* ptr;
//     ptr = head;
//     while (ptr != NULL) {
//         printf("%d", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("\n");
// }

// int main() {
//     int n;
//     printf("Enter no of nodes: ");
//     scanf("%d", &n);
//     int data;
    
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &data);
//         insert_at_end(&start, data);
//     }

//     del_atany_pos(&start, 3);
//     print_list(start);

//     return 0;
// }

//doubly linked list
#include <stdio.h>
#include <stdlib.h>

// Doubly linked list structure
// struct node {
//     int data;
//     struct node* next;
//     struct node* previous;
// };

// // Function to create a new node and return a pointer to it
// struct node* getnode(int x) {
//     struct node* newNode = (struct node*)malloc(sizeof(struct node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed");
//         exit(1);
//     }
//     newNode->data = x;
//     newNode->next = NULL;
//     newNode->previous = NULL;
//     return newNode;
// }

// // Function to insert a node at the beginning of the list
// struct node* insert_at_beginning(struct node* start, int num) {
//     struct node* temp = getnode(num);
//     temp->next = start;
//     if (start != NULL) {
//         start->previous = temp;
//     }
//     return temp;
// }
// void print_list(struct node* start) {
//     struct node* current = start;
//     printf("List: ");
//     while (current != NULL) {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
//     printf("NULL\n");
// }
// int main() {
//     int x;
//     printf("Enter the value to be inserted: ");
//     scanf("%d", &x);
//     struct node* start = getnode(x);
//     printf("Value inserted: %d\n", start->data);
//     int num;
//     printf("Enter number of elements to be inserted at the beginning: ");
//     scanf("%d", &num);
//     printf("Enter the values: ");
//     for (int i = 0; i < num; i++) {
//         int element;
//         scanf("%d", &element);
//         start = insert_at_beginning(start, element);
//     }
//     print_list(start);
//     return 0;
// }

//delete 1st node
struct node {
    int data;
    struct node* next;
    struct node* previous;
};

// Function to create a new node and return a pointer to it
struct node* getnode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = x;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct node* insert_at_beginning(struct node* start, int num) {
    struct node* temp = getnode(num);
    temp->next = start;
    if (start != NULL) {
        start->previous = temp;
    }
    return temp;
}
void print_list(struct node* start) {
    struct node* current = start;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    int x;
    printf("Enter the value to be inserted: ");
    scanf("%d", &x);
    struct node *head=getnode(x);
    struct node *start = head;
    printf("Value inserted: %d\n", start->data);
    int num;
    printf("Enter number of elements to be inserted at the beginning: ");
    scanf("%d", &num);
    printf("Enter the values: ");
    for (int i = 0; i < num; i++) {
        int element;
        scanf("%d", &element);
        start = insert_at_beginning(start, element);
    }
    head=start;
    //deleting 1st node
    struct node *new=head->next;
    print_list(new);
    return 0;
}
