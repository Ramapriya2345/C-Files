#include <stdio.h>
#include <stdlib.h>

struct node {
    float coefficient;
    int exponent;
    struct node* next;
}* head1 = NULL, * head2 = NULL;

struct node* create(struct node* head);
struct node* insert(struct node* head, float co, int ex);
void polyadd(struct node* head1, struct node* head2);
void print(struct node* head);

struct node* create(struct node* head) {
    int n, i;
    printf("Enter the number of terms:");
    scanf("%d", &n);
    float coeff;
    int expo;
    for (i = 0; i < n; i++) {
        printf("Enter the coeff for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

struct node* insert(struct node* head, float co, int ex) {
    struct node* temp;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->coefficient = co;
    new->exponent = ex;
    new->next = NULL;
    if (head == NULL || ex > head->exponent) {
        new->next = head;
        head = new;
    } else {
        temp = head;
        while (temp->next != NULL && temp->next->exponent > ex) {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}

void polyadd(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    struct node *ptr3=head3;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exponent == ptr2->exponent) {
            head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->exponent > ptr2->exponent) {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        } else if (ptr1->exponent < ptr2->exponent) {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL) {
        // head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        // ptr1 = ptr1->next;
        ptr3->next=ptr1;
    }
    while(ptr2 != NULL) {
        // head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
        // ptr2 = ptr2->next;
        ptr3->next=ptr2;
    }
    printf("Resultant Polynomial:\n");
    print(head3);
}
void multiply(struct node *head1,struct node *head2){
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    int res1,res2;
    struct node *head3=NULL;
    while(ptr1!=NULL){
        ptr2=head2;
        while(ptr2!=NULL){
            res1=ptr1->coefficient*ptr2->coefficient;
            res2=ptr1->exponent+ptr2->exponent;
            head3=insert(head3,res1,res2);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    struct node *head=head3;
    struct node *temp=NULL;
    while(head->next!=NULL){
        if(head->exponent==head->next->exponent){
            head->coefficient=head->coefficient+head->next->coefficient;
            temp=head->next;
            head->next=head->next->next;
            free(temp);temp=NULL;
        }
        else{
            head=head->next;
        }
    }
    print(head3);
}
void print(struct node* head) {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%.fx^%d", temp->coefficient, temp->exponent);
            temp = temp->next;
            if (temp != NULL) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    }
}

int main() {
    printf("Enter the first polynomial\n");
    head1 = create(head1);
    printf("Enter the second polynomial\n");
    head2 = create(head2);
    print(head1);
    print(head2);
    polyadd(head1, head2);
    // multiply(head1,head2);
    return 0;
}



