/*//DOUBLE LINKED LIST
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	struct node *next;
	int info;
};
struct node *start=NULL;

struct node* insertatbeg(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	return start;
}
struct node* addtoempty(struct node *start,int data)
{
	
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=NULL;
	start=temp;
	return start;
}

struct node* addatend(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	temp->prev=p;
	temp->next=p->next;
	p->next=temp;
	return start;	
}

struct node* addatpos(struct node *start,int data,int item)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			temp->next=p->next
			temp->prev=p;
		}
		if(p->next!=NULL)
		{
			p->next->prev=temp;
			p->next=temp;
		}
		p=p->next;
	}	
	return start;
}

/*struct node* addbeforepos(struct node *start,int data,int item)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	if(start->info==item)
	{
		temp->prev=NULL;
		temp->next=start;
		start->prev=temp;
	start=temp;
	return start;
	}
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			temp->next=p->prev->next;
			p->prev->next=temp;	
		}
	}*/
	
/*	struct node* delete(struct node*start,int info)
	{
		struct node *temp,*p;
		if(start==NULL)
		{
			printf("empty list\n");
			return start;
		}
		if(start->next!=NULL)
		{
			if(start->data==info)
			{
				temp=start;
				start=NULL;
				free(temp);
				return start;
			}
		}
		
			if(start->data==info)
			{
				temp=start;
				start=start->next;
				start->prev=NULL;
				free(temp);
				return start;
			}
		else
		temp=start->next;
		while(temp->next!=NULL)
		{
			if(temp->next==data)
			{
				
			}
		}
		
	}*/
	//DOUBLE LINKED LIST
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	struct node *next;
	int info;
};
struct node *start=NULL;

struct node* insertatbeg(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	return start;
}
struct node* addtoempty(struct node *start,int data)
{

	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=NULL;
	start=temp;
	return start;
}

struct node* addatend(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	temp->prev=p;
	temp->next=p->next;
	p->next=temp;
	return start;
}

struct node* addatpos(struct node *start,int data,int item)
{
	//printf("Iam here");
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p!=NULL)
	{
		//printf("Iam here");
		if(p->info==item)
		{
			temp->next=p->next;
			temp->prev=p;
		if(p->next!=NULL)
			p->next->prev=temp;
		p->next=temp;
		return start;
		}
		p=p->next;
	}
	return start;
}
struct node * delete_at_beg(struct node*start)
{
	struct node *temp,*p;
		if(start==NULL)
		{
			printf("empty list\n");
			return start;
		}
		temp=start;
		if(start->next==NULL)
		{
				start=NULL;
				free(temp);
				return start;
		}
		else
		{
				start->next->prev=NULL;
				start=start->next;
				free(temp);
				return start;
		}
}

struct node* delete_at_end(struct node *start)
{
	struct node *temp;
	temp=start;
		while(temp->next!=NULL)	
			temp=temp->next;
            temp->prev->next=NULL;
            free(temp);
            return start;

        
}

struct node* delete_node(struct node*start,int info)
	{
		struct node *temp,*p;
		if(start==NULL)
		{
			printf("empty list\n");
			return start;
		}
		if(start->next==NULL)
		{
			if(start->info==info)
			{
				temp=start;
				start=NULL;
				free(temp);
				return start;
			}
			else
                printf("item not found\n");
                return start ;
		}

			if(start->info==info)
			{
				temp=start;
				start=start->next;
				start->prev=NULL;
				free(temp);
				return start;
			}
		else
		temp=start->next;
		while(temp->next!=NULL)
		{
			if(temp->info==info)
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
				return start;
			}
			temp=temp->next;
		}
		if (temp->info == info)
        {
            temp->prev->next=NULL;
            free(temp);
            return start;
        }
        else
            printf("element not found\n");
            return start;
	}

void display(struct node *start)
{
    struct node *p;
    if (start==NULL)
    {
        printf("list empty\n");
        return;
    }
    else
        p=start;
    while (p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
    printf("\n");
    return;
}

int main()
{
    int n=0,i,info,ch;
   /* printf("enter the no. of elements \n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("invalid number \n");
    }
    if(n>=1)
    {   printf("enter data :\t");
        scanf("%d",&info);
        start= addtoempty(start,info);
        printf("enter data\t");
        scanf("%d",&info);
        start=insertatbeg(start,info);
    for (i=3;i<=n;i++)
    {
        printf("enter data\t");
        scanf("%d",&info);
        start=addatend(start,info);
    }
    printf("linked list : \n");}
    display(start);
    while(1)
    {
        printf("\n1 -> delete 2-> exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter data\t");
            scanf("%d",&info);
            start=delete_node(start,info);
            display(start);
        }
        else if (ch==2)
        exit(1);
          else
            continue;
    }*/

while(1)
{
	printf("1:-Insert\t 2:-Delete\t3)Display\t4)Exit\t");
	scanf("%d",&ch);
	if(ch==1)
	{
		if(start==NULL)
		{
			printf("enter data :\t");
      		scanf("%d",&info);
        	start= addtoempty(start,info);
        	n++;
		}
		else
		{
			printf("1)add at begining\t2)add at end\t3)add at pos\t");
			scanf("%d",&ch);
			if(ch==1)
			{
				 printf("enter data\t");
       			 scanf("%d",&info);
        		 start=insertatbeg(start,info);
        		 n++;
			}
			else if(ch==2)
			{
				printf("enter data\t");
        		scanf("%d",&info);
        		start=addatend(start,info);			
				n++;
			}
	
			else
			{
				int pos;
				printf("Enter the element:-\t");
				scanf("%d",&pos);
				printf("enter data\t");
        		scanf("%d",&info);
        		start=addatpos(start,info,pos);			
			
			}  
		}
		display(start);
	}
	else if(ch==2)
	{
		if(start==NULL)
		printf("Empty list\n");
		else
		{
	
		printf("!)Delete at begining\t2)Delete element\t3)Delete at end\t");
		scanf("%d",&ch)	;
		if(ch==1)
		start=delete_at_beg(start);
		 else if(ch==2)
		{
			 printf("enter data\t");
            scanf("%d",&info);
            start=delete_node(start,info);
            n--;
        }
		else
		{
			start=delete_at_end(start);	
			n--;
		}
		display(start);
}
	}
	else if(ch==3)
	{
		display(start);
	}
	else
	exit(1);
}
}

