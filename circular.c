//circular liked list
//important points abt cll
//i)cll is type of link list comprises of data and link fields where in last node address is pointing to first node 
//ii)transversing is easier
//iii)there is no null field in the list
//iv)improper programming leads to infinite loop
//v)cll is use to implement data structure like satck queue and heap
//vi)implementation of round robin scheduling
#include<stdlib.h>
#include<stdio.h>

//to create node
struct node
{
    int info;
    struct node *link;
};

void display(struct node *tail)
{
    struct node *tmp=tail->next;
    //one pointer points to last node while the other traverse
    //through entire list
    do
    {
        printf("%d\n",p->info);
        tmp=tmp->next;
    } while (tmp!=tail->next);
    
}
int main()
{
    
    int data=34;
    struct node *tail;
    tail=circularsingly(data);

    printf("%d\n",tail->info );
    return 0;
}
