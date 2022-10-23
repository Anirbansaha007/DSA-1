//24->45->56->100
#include<stdio.h>
#include<stdlib.h>

//creating node
struct node 
{
    int info;
    struct node *link;
};

struct node *first(struct node *s,int a)
{
    s=malloc(sizeof(struct node));
    s->info=a;
    s->link=NULL;

    return s;
}

void add_end(struct node **s,int a)
{
    struct node *new=malloc(sizeof(struct node));
    new->info=a;
    new->link=NULL;

    struct node *tmp=*s;
    while((tmp->link)!=NULL)
    {
        tmp=tmp->link;
    }
    tmp->link=new;
}

void insert(struct node **s,int a)
{
    // struct node *new=malloc(sizeof(struct node));
    // new->info=a;
    // new->link=NULL;

    // struct node *tmp=*s;
    // struct node *tmp2=NULL;
    // if( a<(tmp->info))//to insert node in the beginning
    // {
    //     new->link=tmp;
    //     tmp=new;
    // }
    // else
    // {
    //     while((tmp->info)<=a)
    //     {
    //         tmp2=tmp;
    //         tmp=tmp->link;
    //     }
    //     new->link=tmp;//new->link=tmp2->link
    //     tmp2->link=new;
    // }

    struct node *new=malloc(sizeof(struct node));
    new->info=a;
    new->link=NULL;

    struct node *tmp=*s;
    if(((*s)->info)>a)//to add in the beginning of the linked list
    {
        printf("entered loop");
        new->link=*s;
        *s=new;
        return ;
    }
    else
    {
        while(tmp->link!=NULL && (tmp->link->info)<=a )
        {
            //tmp2=tmp;
            tmp=tmp->link;
        }
        new->link=tmp->link;
        tmp->link=new;
    }
}

void display(struct node *s)
{
    struct node *tmp=s;
    while(tmp!=NULL)
    {
        printf("%d\n",tmp->info);
        tmp=tmp->link;
    }
};

int main()
{
    int d;
    printf("enter an element to insert in between");
    scanf("%d",&d);
    struct node *head;
    head=first(head,24);
    display(head);
    printf("--\n");
    add_end(&head,45);
    printf("--\n");
    display(head);
    add_end(&head,56);
    printf("--\n");
    display(head);
    add_end(&head,100);
    printf("--\n");
    display(head);
    insert(&head,d);
    printf("--\n");
    display(head);
}