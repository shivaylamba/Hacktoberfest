#include<stdio.h>
#include<stdlib.h>
struct node
{
    int x;
    struct node *next;
}*start;
void in_end(int x)
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->x=x;
    temp->next=NULL;
    if(start==NULL)
    start=temp;
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=temp;
    }
}
void del_allnode()
{
    struct node *p;
    if(start==NULL)
        printf("List is empty.");
    else
    {   p=start;
        for(;p!=NULL;)
        {
            start=start->next;
            p->next=NULL;
            free(p);
            p=start;
        }
    }
}
void main()
{
    int n,x,k;
    start=NULL;
    struct node *p;
    printf("enter the number of element\n");
    scanf("%d",&n);
    printf("enter the numbers\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        in_end(x);
    }
    del_allnode();
}

