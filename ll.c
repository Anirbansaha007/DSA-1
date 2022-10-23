#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

struct node *head; 

void insert_at_start(int val);
void insert_at_end(int val, node* head);
void display(node* head);
void insert_at_mid(int val, node* prev);
// void delete_first(node* head);
void delete_end(node* head);
void delete_a_particular(int val);
void reverse(node** head);

int main(){

    // node* a = NULL;
    // a = (node *)malloc(sizeof(node));

    node* a = (node *)malloc(sizeof(node));
    node* b = (node *)malloc(sizeof(node));
    node* c = (node *)malloc(sizeof(node));


    head = a;
    a->data = 3;
    a->link = b;

    b->data = 33;
    b->link = c;

    c->data = 333;
    c->link = NULL;

    display(head);
    insert_at_start(34);
    insert_at_end(3333, head);
    insert_at_mid(99, b);
    display(head);
    // delete_first(head);
    delete_end(head);
    delete_a_particular(99);
    display(head);
    reverse(&head);
    display(head);
    return 0;
}

//Insertion
void insert_at_start(int val){
    node* newnode = (node*)malloc(sizeof(node));
    // newnode = head;
    newnode->data = val;
    newnode->link = head;
    // newnode = head;
    head = newnode;
    }

void insert_at_end(int val, node* head){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->link = NULL;
    node* temp = (node *)malloc(sizeof(node));
    temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
}
void display(node* head){
    node* temp = (node *)malloc(sizeof(node));
    temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("END\n");
}

void insert_at_mid(int val, node* prev){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->link = prev->link;
    prev->link = newnode;
}

//Deletion
void delete_first(node* head){
    node* temp = (node*)malloc(sizeof(node));
    temp = head;
    free(temp);
    head = head->link;
    
}

void delete_end(node* head){
    node* temp = (node*)malloc(sizeof(node));
    temp = head;
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}

void delete_a_particular(int val){
    node* temp = (node*)malloc(sizeof(node));
    temp = head;
    while(temp->link->data != val){
        temp = temp->link;
    }
    free(temp->link);
    temp->link = temp->link->link;

}

void reverse(node** h){
    node* next =  (node*)malloc(sizeof(node));
    node* prev =  (node*)malloc(sizeof(node));
    node* curr =  (node*)malloc(sizeof(node));

    next = NULL;
    prev = NULL;
    curr = *h;
    
    while(curr != NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    *h = prev;
    
}



// c program to reverse a linkedlist.