#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct tree
{
    struct node *root;
};

void init(struct tree *pt)
{
    pt->root=NULL;
}

void create(struct tree *pt)
{
    int wish;
    struct node *tmp,*p,*q;
    printf("enter the root info\n");
    pt->root=malloc(sizeof(struct node));
    scanf("%d",&(pt->root->data));
    pt->root->left=NULL;
    pt->root->right=NULL;
    do
    {
        
        struct node *p,*q;
        struct node *tmp=malloc(sizeof(struct node));
        printf("enter an element\n");
        scanf("%d",&(tmp->data));
        tmp->left=NULL;
        tmp->right=NULL;
        q=NULL;
        p=pt->root;
        while(p!=NULL)
        {
            q=p;
            if((tmp->data)<(p->data))
            {
                p=p->left;
            }
            else
            {
                p=p->right;
            }
        }
        if((tmp->data)<(q->data))
        {
            q->left=tmp;
        }
        else
        {
            q->right=tmp;
        }
        printf("do u want to add any node:\n");
        scanf("%d",&wish);
    } while (wish);
    
}

void traverse_inorder(struct node *p)
{
    if(p==NULL)
    {
        return ;
    }
    traverse_inorder(p->left);
    printf("%d\n",p->data);
    traverse_inorder(p->right);
}

struct node *minValueNode(struct node *node) {
  struct node *tmp=node->left;
  int key=node->data;
  printf("%d\n",key);
  while(tmp!=NULL)
  {
    if(key<(tmp->data))
    {
    
        tmp=tmp->left;
    }
    else if(key>(tmp->data))
    {
        tmp=tmp->right;
    }
    else
    {
        return tmp;
    }
  }
}

void intr(struct tree *p)
{
    traverse_inorder(p->root);
}

int search_now(struct node *p,int key)
{
    struct node *tmp=p;
    while(tmp!=NULL)
    {
        if(key<(tmp->data))
        {
            tmp=tmp->left;
        }
        else if(key>(tmp->data))
        {
            tmp=tmp->right;
        }
        else
        {
            if(key==tmp->data)
            {
                return tmp->data;
            }
        }
    }
    return -1;
}

int search(struct tree *p,int key)
{
    int n=search_now(p->root,key);
    return n;
}
int main()
{
    int n;
    struct tree obj;
    create(&obj);
    intr(&obj);
    // printf("do u want to search for an element 0/1 ?\n");
    // scanf("%d",&n);
    // if(n)
    // {
    //     printf("enter the element to search\n");
    //     scanf("%d",&n);
    //     n=search(&obj,n);
    //     if(n==-1)
    //     {
    //         printf("element not found");
    //     }
    //     else
    //     {
    //         printf("element is found\n");
    //     }
    // }
    // printf("\n");
    struct node *tmp=minValueNode(&obj);
    printf("%d",tmp->data);
}