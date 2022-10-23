#include<stdio.h>
#include<stdlib.h>

//creating node for double linked list
struct node
{
    struct node *prev;
    int info;
    struct node *next; 
};

void delete_entire(struct node **s)
{
    struct node *tmp=*s;
    while((*s)!=NULL)
    {
        *s=(*s)->next;
        free(tmp);
        tmp=NULL;
        tmp=*s;
    }
}

void display(struct node *s)
{
    struct node *tmp=s;
    while(tmp!=NULL)
    {
        printf("%d\n",tmp->info);
        tmp=tmp->next;
    }
}

void delete(struct node **s,int a)
{
    //add if statement for deletion of first and last node and respective codes
    struct node *tmp=*s;
    int count=1;//becuase when we enter into loop we are already pointing to first node
    while(count!=a)
    {
        tmp=tmp->next;
        count++;
    }
    tmp->prev->next=NULL;//first make prev of prev node null because address of prev  node will be saved in deleting
    //once  deleting node is removed address of prev can't be obtained
    tmp->prev->next=tmp->next;//assigning prev node of deleting node to next node of deleting node
    tmp->next->prev=tmp->prev; 
    free(tmp);
    tmp=NULL;
    //youtube code
    /*struct node *temp=head;
    struct node *tmp2=NULL;
    if(position==1)
    {
        head=delfirst(head);
        return head;
    }
    while(position>1)
    {
        temp=temp->next;
        position--;
    }
    if(temp->next == NULL)
    {
        head=dellast(head);
    }
    else
    {
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }*/
}

int main()
{
    //creating double linked list
    struct node *head;
    head=malloc(sizeof(struct node));
    int a,b,c;
    printf("enter three elements");
    scanf("%d %d %d",&a,&b,&c);
    head->prev=NULL;
    head->info=a;
    head->next=NULL;

    struct node *current;
    current=malloc(sizeof(struct node));
    current->info=b;
    current->prev=NULL;
    current->next=NULL;

    head->next=current;
    current->prev=head;

    current=malloc(sizeof(struct node));
    current->prev=NULL;
    current->info=c;
    current->next=NULL;

    head->next->next=current;
    current->prev=head->next->next;

    int d;
    printf("enter the node number to remove");
    scanf("%d",&d);
    delete(&head,d);
    display(head);
    delete_entire(&head);
}