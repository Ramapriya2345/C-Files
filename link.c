// #include<stdio.h>
// #include<stdlib.h>
// creating nodes
// struct node{
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *head=NULL;
//     head=(struct node*)malloc(sizeof(struct node));
//     head->data=65;
//     head->link=NULL;
//     printf("%d",head->data);
//     return 0;
    
// }

// single linked list
// struct node
// {
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *head=NULL;
//     head=malloc(sizeof(struct node));
//     head->data=65;
//     head->link=NULL;
//     head=malloc(sizeof(struct node));
//     head->data=98;
//     head->link=NULL;
//     printf("%d",head->data);
//     return 0;

// }//the prob in this code is that head is now pointing to the second node and not the 1st one
// so we change the name now
// struct node
// {
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *head=NULL;
//     head=malloc(sizeof(struct node));
//     head->data=65;
//     head->link=NULL;
//     struct node *current=malloc(sizeof(struct node));
//     current->data=98;
//     current->link=NULL;
//     head->link=current;//the 1st node is connected to second node
//     current=malloc(sizeof(struct node));
//     current->data=8;
//     current->link=NULL;
//     head->link->link=current;
//     return 0; 
// }

// //traversing a single linked list & count no of nodes
// struct node {
//     int data;
//     struct node *link;
// };

// void countnodes(struct node *head);

// int main() {
//     struct node *head = NULL;
//     head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     struct node *current = malloc(sizeof(struct node));
//     current->data = 98;
//     current->link = NULL;
//     head->link = current; // the 1st node is connected to the second node
    
//     struct node *newNode = malloc(sizeof(struct node)); // Corrected this line
//     newNode->data = 98;
//     newNode->link = NULL;
//     head->link->link = newNode; 
    
//     countnodes(head);
    
//     // Free memory
//     free(head);
//     free(current);
//     free(newNode);
    
//     return 0;
// }

// void countnodes(struct node *head) {
//     int count = 0;
//     if (head == NULL) {
//         printf("Linked list is empty");
//     } else {
//         while (head != NULL) {
//             count++;
//             head = head->link;
//         }
//         printf("%d", count);
//     }
// }

// printing data
// traversing a single linked list & count no of nodes
// struct node {
//     int data;
//     struct node *link;
// };
// void printnodes(struct node *head);
// int main() {
//     struct node *head = NULL;
//     head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;
    
//     struct node *current = malloc(sizeof(struct node));
//     current->data = 98;
//     current->link = NULL;
//     head->link = current; // the 1st node is connected to the second node
    
//     struct node *newNode = malloc(sizeof(struct node)); // Corrected this line
//     newNode->data = 108;
//     newNode->link = NULL;
//     head->link->link = newNode; // Corrected this line
    
//     printnodes(head);
    
//     // Free memory
//     free(head);
//     free(current);
//     free(newNode);
    
//     return 0;
// }

// void printnodes(struct node *head) {
//     if (head == NULL) {
//         printf("Linked list is empty");
//     } else {
//         while (head != NULL) {
//             printf("%d\n",head->data);
//             head=head->link;
//         }
//     }
// }

// adding element at the end
// #include <stdio.h>
// #include <stdlib.h>

// structure declaration
// struct node
// {
//     int data;
//     struct node *link;
// };

// //function declaration
// void add_at_end(struct node *head, int data);
// void print_list(struct node *head);

// //main function
// int main()
// {
//     //creating head node
//     struct node *head = NULL;
//     head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     //creating second node
//     struct node *current = malloc(sizeof(struct node));
//     current->data = 98;
//     current->link = NULL;
//     head->link = current; //connecting 1st node to 2nd node

//     //creating third node
//     struct node *newNode = malloc(sizeof(struct node));
//     newNode->data = 108;
//     newNode->link = NULL;
//     current->link = newNode; //connecting 2nd node to 3rd node or head->link->link

//     //adding element at the end
//     add_at_end(head, 76);

//     //printing the list
//     print_list(head);

//     // Free memory
//     free(head);
//     free(current);
//     free(newNode);

//     return 0;
// }

// //function to add element at the end
// void add_at_end(struct node *head, int data)
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     while (head->link != NULL)
//     {
//         head= head->link;
//     }//time complexity O(n)
//     head->link = temp;
// }

// //function to print the list
// void print_list(struct node *head)
// {
//     struct node *ptr;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d\n", ptr->data);
//         ptr = ptr->link;
//     }
// }

// Optimal code(eliminating time complexity)
// structure declaration
// struct node
// {
//     int data;
//     struct node *link;
// };

// //function declaration
// struct node* add_at_end(struct node *ptr, int data);
// void print_list(struct node *head);

// //main function
// int main()
// {
//     //creating head node
//     struct node *head = NULL;
//     head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     //creating second node
//     struct node *curr = head;
//     curr=add_at_end(curr,78);
//     curr=add_at_end(curr,86);
//     curr=add_at_end(curr,91);
//     curr=head;//to point back to the 1st node
//     while(curr!=NULL){
//         printf("%d\n",curr->data);
//         curr=curr->link;
//     }

//     // Free memory
//     free(head);
//     free(curr);
//     return 0;
// }

// //function to add element at the end
// struct node* add_at_end(struct node *ptr, int data)
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp;
// }

// //or
// //Optimal code(eliminating time complexity)
// //structure declaration
// struct node
// {
//     int data;
//     struct node *link;
// };

// //function declaration
// struct node* add_at_end(struct node *ptr, int data);
// void print_list(struct node *head);

// //main function
// int main()
// {
//     //creating head node
//     struct node *head = NULL;
//     head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     //creating second node
//     int num[]={78,86,91};
//     struct node *curr = head;
//     for(int i=0;i<sizeof(num)/sizeof(int);i++){
//           curr=add_at_end(curr,num[i]);
//     }
//     curr=head;//to point back to the 1st node
//     while(curr!=NULL){
//         printf("%d\n",curr->data);
//         curr=curr->link;
//     }

//     // Free memory
//     free(head);
//     free(curr);
//     return 0;
// }

// //function to add element at the end
// struct node* add_at_end(struct node *ptr, int data)
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp;//time complexity O(1);
// }

// using arrays
// when size is more
// int addatend(int *a, int size, int n);
// int main() {
//     int a[10];
//     int n, i;
//     printf("Enter no of elements:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     int num;
//     printf("Num to include: ");
//     scanf("%d", &num);
//     n = addatend(a, n, num);
//     for (i = 0; i < n; i++) {
//         printf("%d ", a[i]); 
//     }
// }
// int addatend(int *a, int size, int n) {
//     a[size] = n;
//     size++;
//     return size;
// }


// when u don't have enough size
// int addatend(int *a,int *b,int size,int n);
// int main(){
//     int a[4];
//     int n,i;
//     printf("Enter no of elements:");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     int num;
//     printf("Num to include");
//     scanf("%d",&num);
//     if(n==sizeof(a)/sizeof(a[0])){
//     int *b=malloc(sizeof(int)*n);
//     n=addatend(a,b,n,num);
//     for(i=0;i<n;i++){
//      printf("%d",b[i]);
//     }
//     }
    
// }
// int addatend(int *a,int *b,int size,int n){
//      for(int i=0;i<size;i++){
//             b[i]=a[i];
//         }
//     b[size]=n;
//     size++;
//     return size;
// }

// add an element at beginning
// struct node *addbeg(struct node *head,int data);
// struct node{
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *head=malloc(sizeof(struct node));
//     head->data=65;
//     head->link=NULL;
//     struct node *ptr=malloc(sizeof(struct node));
//     ptr->data=78;
//     ptr->link=NULL;
//     head->link=ptr;
//     int data=5;
//     head=addbeg(head,data);
//     while(head!=NULL){
//         printf("%d\n",head->data);
//         head=head->link;
//     }

// }
// struct node *addbeg(struct node *head,int data){
//     struct node *new=malloc(sizeof(struct node));
//     new->data=data;
//     new->link=NULL;
//     new->link=head;
//     return new;
// }

// or

// struct node{
//     int data;
//     struct node *link;
// };
// void addbeg(struct node **head,int data);
// int main(){
//     struct node *head=malloc(sizeof(struct node));
//     head->data=65;
//     head->link=NULL;
//     struct node *ptr=malloc(sizeof(struct node));
//     ptr->data=78;
//     ptr->link=NULL;
//     head->link=ptr;
//     int data=5;
//     addbeg(&head,data);
//     while(head!=NULL){
//         printf("%d\n",head->data);
//         head=head->link;
//     }
// }
// void addbeg(struct node **head,int data){
//     struct node *new=malloc(sizeof(struct node));
//     new->data=data;
//     new->link=NULL;
//     new->link=*head;
//     *head=new;
// }


// to insert at specific index
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *link;
// };

// // Function declarations
// struct node* add_at_end(struct node *ptr, int data);
// void print_list(struct node *head);
// void insert(struct node *head, int data, int pos);

// int main() {
//     // Creating head node
//     struct node *head = NULL;
//     head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     // Creating second node
//     struct node *curr = head;
//     curr = add_at_end(curr, 78);
//     curr = add_at_end(curr, 86);
//     curr = add_at_end(curr, 91);
//     insert(head, 69, 4);
//     curr = head; // Pointing back to tstructhe 1st node
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
//     return 0;
// }

// // Function to add element at the end
// struct node* add_at_end( node *ptr, int data) {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp;
// }

// // Function to insert element at a specific position
// void insert(struct node *head, int data, int pos) {
//     struct node *ptr = malloc(sizeof(struct node));
//     ptr->data = data;
//     ptr->link = NULL;
//     pos--;

//     while (pos != 1) {
//         head = head->link;
//         pos--;
//     }    
//     ptr->link = head->link;
//     head->link = ptr;
// }


// using arrays
// inserting at a specific pos
// void insert(int *a, int size, int data,int pos);
// int main() {
//     int a[10];
//     int n, i;
//     printf("Enter no of elements:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     int num;
//     insert(a,n,65,4);
//     n++;
//     for (i = 0; i < n; i++) {
//         printf("%d ", a[i]); 
//     }
// }
// void insert(int *a, int size, int data,int pos) {
//     for(int i=size;i>=pos;i--){
//         a[i]=a[i-1];
//     }
//     a[pos-1]=data;
//     size++;
// }

// deleting 1st element
// void delete1st(int *a, int size);
// int main() {
//     int a[10];
//     int n, i;
//     printf("Enter no of elements:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     delete1st(a,n);
//     n--;
//     for (i = 0; i < n; i++) {
//         printf("%d ", a[i]); 
//     }
// }
// void delete1st(int *a, int size) {
//     for(int i=0;i<size-1;i++){
//         a[i]=a[i+1];
//     }
// }

// deleting at specific index
// void deletepos(int *a, int size,int pos);
// int main() {
//     int a[10];
//     int n, i;
//     printf("Enter no of elements:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     deletepos(a,n,3);
//     n--;
//     for (i = 0; i < n; i++) {
//         printf("%d ", a[i]); 
//     }
// }
// void deletepos(int *a, int size,int pos) {
//     for(int i=pos-1;i<size;i++){
//         a[i]=a[i+1];
//     }
// }

// singly linked list creating and printing using array
// struct node{
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *curr = malloc(sizeof(struct node));
//     struct node *head = curr; // A temporary pointer to traverse the linked list
//     int a[]={1,2,3};
//     for(int i=0;i<3;i++){
//         head->data=a[i];
//         if(i<2){
//             head=head->link;// Move the pointer to the next node
//         }
//         else{
//             head->link=NULL;// Set the last node's link to NULL
//         }
//     }
//     head=curr;// Reset to head for printing
//     while(head!=NULL){
//         printf("%d\n",head->data);
//         head=head->link;
//     }
    
// }

// deleting 1st element
// struct node{
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *curr = malloc(sizeof(struct node));
//     struct node *head = curr; // A temporary pointer to traverse the linked list
//     int a[]={1,2,3};
//     for(int i=0;i<3;i++){
//         head->data=a[i];
//         if(i<2){
//             head=head->link;// Move the pointer to the next node
//         }
//         else{
//             head->link=NULL;// Set the last node's link to NULL
//         }
//     }
//     curr=curr->link;
//     head=curr;// Reset to head for printing
//     while(head!=NULL){
//         printf("%d\n",head->data);
//         head=head->link;
//     }
// }
// doubt in the time complexity of array & linked list
// or
// #include <stdio.h>
// #include <stdlib.h>
// struct node {
//     int data;
//     struct node *link;
// };
// int main() {
//     struct node *curr = malloc(sizeof(struct node));
//     struct node *head = curr; // A temporary pointer to traverse the linked list
//     int a[] = {1, 2, 3};   
//     // Creating the linked list
//     for (int i = 0; i < 3; i++) {
//         curr->data = a[i];
//         if (i < 2) {
//             curr->link = malloc(sizeof(struct node));
//             curr = curr->link; // Move the pointer to the next node
//         } else {
//             curr->link = NULL; // Set the last node's link to NULL
//         }
//     } 
//     // Deleting the first element (changing head)
//     head = head->link;

//     // Reset to head for printing
//     curr = head;
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
//     // Free memory
//     curr = head;
//     while (curr != NULL) {
//         struct node *temp = curr;
//         curr = curr->link;
//         free(temp);
//     }
//     return 0;
// }

// deleting at end
// #include <stdio.h>
// #include <stdlib.h>
// struct node {
//     int data;
//     struct node *link;
// };
// int main() {
//     struct node *curr = malloc(sizeof(struct node));
//     struct node *head = curr; // A temporary pointer to traverse the linked list
//     int a[] = {1, 2, 3,4,5};   
//     // Creating the linked list
//     for (int i = 0; i < 5; i++) {
//         curr->data = a[i];
//         if (i < 3) {
//             curr->link = malloc(sizeof(struct node));
//             curr = curr->link; // Move the pointer to the next node
//         } else if(i==3){
//             curr->link = NULL; // Set the last node's link to NULL
//             break;
//         }
//     } 
//     // Reset to head for printing
//     curr = head;
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
//     // Free memory
//     curr = head;
//     while (curr != NULL) {
//         struct node *temp = curr;
//         curr = curr->link;
//         free(temp);
//     }
//     return 0;
// }

// deleting last element of linked list
// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a node
// struct node {
//     int data;
//     struct node *link;
// };

// // Function to delete the last element of the linked list
// void deleteLast(struct node **head) {
//     if (*head == NULL) {
//         printf("List is empty\n");
//         return;
//     } else if ((*head)->link == NULL) {
//         // Only one node in the list
//         free(*head);
//         *head = NULL;
//         return;
//     }

//     struct node *temp = *head;
//     while (temp->link->link != NULL) {
//         temp = temp->link;
//     }

//     // Now temp points to the second last node
//     free(temp->link);
//     temp->link = NULL;
// }

// // Function to print the linked list
// void printList(struct node *head) {
//     struct node *temp = head;
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->link;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct node *head = NULL;
//     struct node *temp;

//     // Create the linked list
//     for (int i = 1; i <= 5; i++) {
//         struct node *newNode = (struct node *)malloc(sizeof(struct node));
//         newNode->data = i * 10;
//         newNode->link = NULL;

//         if (head == NULL) {
//             head = newNode;
//             temp = newNode;
//         } else {
//             temp->link = newNode;
//             temp = newNode;
//         }
//     }

//     printf("Original Linked List:\n");
//     printList(head);

//     // Delete the last element
//     deleteLast(&head);

//     printf("Linked List after deleting the last element:\n");
//     printList(head);

//     // Free memory
//     while (head != NULL) {
//         temp = head;
//         head = head->link;
//         free(temp);
//     }

//     return 0;
// }

// deleting at specific position
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *link;
// };

// void deletepos(struct node **head, int pos);

// // Function declarations
// struct node* add_at_end(struct node *ptr, int data);
// void print_list(struct node *head);
// void insert(struct node *head, int data, int pos);

// int main() {
//     // Creating head node
//     struct node *head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     // Creating second node
//     struct node *curr = head;
//     curr = add_at_end(curr, 78);
//     curr = add_at_end(curr, 86);
//     curr = add_at_end(curr, 91);
//     insert(head, 69, 4);
//     deletepos(&head, 1);
//     curr = head; // Pointing back to the 1st node
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
//     return 0;
// }

// void deletepos(struct node **head, int pos) {
//     if (pos == 1) {
//         struct node *temp = *head;
//         *head = (*head)->link;
//         free(temp);
//         return;
//     }

//     struct node *prev = *head;
//     struct node *curr = (*head)->link;
    
//     pos--;
//     while (pos > 1 && curr != NULL) {
//         prev = curr;
//         curr = curr->link;
//         pos--;
//     }
    
//     if (curr == NULL) {
//         printf("Position out of bounds.\n");
//         return;
//     }
    
//     prev->link = curr->link;
//     free(curr);
// }


// // Function to add element at the end
// struct node* add_at_end(struct node *ptr, int data) {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp;
// }

// // Function to insert element at a specific position
// void insert(struct node *head, int data, int pos) {
//     struct node *ptr = malloc(sizeof(struct node));
//     ptr->data = data;
//     ptr->link = NULL;
//     pos--;

//     while (pos > 1) {
//         head = head->link;
//         pos--;
//     }
//     ptr->link = head->link;
//     head->link = ptr;
// }

// dletentire
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *link;
// };

// struct node *deleteentire(struct node *head);

// // Function declarations
// struct node* add_at_end(struct node *ptr, int data);
// void print_list(struct node *head);
// void insert(struct node *head, int data, int pos);

// int main() {
//     // Creating head node
//     struct node *head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     // Creating second node
//     struct node *curr = head;
//     curr = add_at_end(curr, 78);
//     curr = add_at_end(curr, 86);
//     curr = add_at_end(curr, 91);
//     insert(head, 69, 4);
//     head=deleteentire(head);
//     curr = head; // Pointing back to the 1st node
//     if(curr==NULL){
//             printf("success");
//     }
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
//     return 0;
// }

// struct node *deleteentire(struct node *head) {
// struct node *temp=head;
// while(temp->link!=NULL){
//     temp=temp->link;
//     free(head);
//     head=temp;
// }

// }


// // Function to add element at the end
// struct node* add_at_end(struct node *ptr, int data) {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp;
// }

// // Function to insert element at a specific position
// void insert(struct node *head, int data, int pos) {
//     struct node *ptr = malloc(sizeof(struct node));
//     ptr->data = data;
//     ptr->link = NULL;
//     pos--;

//     while (pos > 1) {
//         head = head->link;
//         pos--;
//     }
//     ptr->link = head->link;
//     head->link = ptr;
// }

// or
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *link;
// };

// void deleteentire(struct node **head);

// // Function declarations
// struct node* add_at_end(struct node *ptr, int data);
// void print_list(struct node *head);
// void insert(struct node *head, int data, int pos);

// int main() {
//     // Creating head node
//     struct node *head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     // Creating second node
//     struct node *curr = head;
//     curr = add_at_end(curr, 78);
//     curr = add_at_end(curr, 86);
//     curr = add_at_end(curr, 91);
//     insert(head, 69, 4);
//     deleteentire(&head);
//     curr = head; // Pointing back to the 1st node
//     if(curr==NULL){
//             printf("success");
//     }
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }
//     return 0;
// }

// void deleteentire(struct node **head) {
//     while (*head != NULL) {
//         struct node *temp = *head;
//         *head = (*head)->link;
//         free(temp);
//     }
// }
// // Function to add element at the end
// struct node* add_at_end(struct node *ptr, int data) {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp;
// }

// // Function to insert element at a specific position
// void insert(struct node *head, int data, int pos) {
//     struct node *ptr = malloc(sizeof(struct node));
//     ptr->data = data;
//     ptr->link = NULL;
//     pos--;

//     while (pos > 1) {
//         head = head->link;
//         pos--;
//     }
//     ptr->link = head->link;
//     head->link = ptr;
// }

// //reversing list
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *link;
// };

// struct node* add_at_end(struct node *ptr, int data);
// void reverse(struct node **head);

// int main() {
//     // Creating head node
//     struct node *head = malloc(sizeof(struct node));
//     head->data = 65;
//     head->link = NULL;

//     // Creating second node
//     int num[] = {78, 86, 91};
//     struct node *curr = head;
//     for (int i = 0; i < sizeof(num) / sizeof(int); i++) {
//         curr = add_at_end(curr, num[i]);
//     }

//     reverse(&head);

//     curr = head; // Pointing back to the 1st node
//     while (curr != NULL) {
//         printf("%d\n", curr->data);
//         curr = curr->link;
//     }

//     // Free memory
//     curr = head;
//     while (curr != NULL) {
//         struct node *temp = curr;
//         curr = curr->link;
//         free(temp);
//     }

//     return 0;
// }

// // Function to add element at the end
// struct node* add_at_end(struct node *ptr, int data) {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp; // time complexity O(1);
// }

// void reverse(struct node **head) {
//     struct node *prev = NULL;
//     struct node *current = *head;
//     struct node *next = NULL;

//     while (current != NULL) {
//         next = current->link;
//         current->link = prev;
//         prev = current;
//         current = next;
//     }

//     *head = prev;
// }

