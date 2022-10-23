#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

struct node* head;
// struct node* tail = gettail(head);


void display(node* head);
void insert_at_start(int val, node** head);
void insert_at_end(int val, node* head); 
void delete_at_end(node* head);
void delete_at_head(node** head);

int main(){
    node* a = (node*)malloc(sizeof(node));
    node* b = (node*)malloc(sizeof(node));
    node* c = (node*)malloc(sizeof(node));
    node* d = (node*)malloc(sizeof(node));
    node* e = (node*)malloc(sizeof(node));
    head = a;
    a->data = 10;
    a->next = b;

    b->data = 20;
    b->next = c;

    c->data = 30;
    c->next = d;

    d->data = 40;
    d->next = e;

    e->data = 50;
    e->next = a;

    display(head);
    // insert_at_end(44, a);
    insert_at_start(34, &head); 
    insert_at_end(44, head);
    display(head);
    delete_at_end(head);
    delete_at_head(&head);
    display(head);


    return 0;
}

void display(node* head){
    node* temp = head;
    printf("%d->", temp->data);
    temp = temp->next;
    while(temp != head){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



void insert_at_start(int val, node** head){
    node* newnode = (node*)malloc(sizeof(node));

    node* temp = *head;
    while(temp->next != *head){
        temp = temp->next;
    }
    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;
    *head = newnode;
    // *head = newnode;
}

void insert_at_end(int val, node* head){
    node* newnode = (node*)malloc(sizeof(node));
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    newnode->data = val;
    newnode->next = head;
    temp->next = newnode;
    // newnode = temp;
    temp = newnode;
    // *head = newnode;
}

void delete_at_end(node* head){
    node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    temp->next = head;
    free(temp->next);
}
void delete_at_head(node** head){
    node* temp = *head;
    node* temp1 = *head;
    while(temp->next != *head){
        temp = temp->next;
    }
    temp->next = (*head)->next;
    *head = temp->next;
    // free(temp1);
}

