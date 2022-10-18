#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;

};
struct node*head=NULL;
struct node*last=NULL;

void insertBeg(int data)
{
  struct node*newnode=(struct node*)malloc(sizeof(struct node));
  
  newnode->data=data;
  newnode->prev=NULL;
  newnode->next=NULL;
  if(head==NULL)
   {
       head=newnode;
       last=newnode;
   }
  else{
      head->prev=newnode;
      newnode->next=head;
      head=newnode;
  }
}

void insertEnd(int data)
{
 struct node*newnode=(struct node*)malloc(sizeof(struct node));
  
  newnode->data=data;
  newnode->prev=NULL;
  newnode->next=NULL;
  if(head==NULL)
   {
       head=newnode;
       last=newnode;
   }
  else{
     newnode->prev=last;
     last->next=newnode;
     last=newnode;
  }
}

void insertPos(int data,int pos){
  struct node*newnode,*ptr;
  newnode=(struct node*)malloc(sizeof(struct node));
  ptr=head;
  newnode->data=data;
  newnode->prev=NULL;
  newnode->next=NULL;
  if(head==NULL)
   {
       head=newnode;
       last=newnode;
   }
   else {
       for(int i=1;i<pos-1;i++){
          ptr=ptr->next;
        }
    newnode->next=ptr->next;
    newnode->next->prev=newnode;
    newnode->prev=ptr;
    ptr->next=newnode;
   }

}
void traverse(){
    struct node*ptr=head;
    printf("\n ELEMENTS ARE:");
    while (ptr!=NULL)
    {
      printf("\t%d\t",ptr->data);
      ptr=ptr->next;
    }
    
}

void search(int key){
    struct node*ptr=head;
    int pos=1,flag=0;
    if(head==NULL)printf("\n Cannot search:");
    else{
        while(ptr!=NULL){
            if(ptr->data==key)
             {
                 flag=1;break;
             }
             
                 ptr=ptr->next;
                 pos++;
             
        }
        if(flag==1)printf("\nElement found at %d",pos);
        else{printf("\nElement not found");}
    }
}

void main()
{
    int choice,data,pos,key;
    do{
    printf("\n1.INSERT AT BEG:");
    printf("\n2.InsertEnd");
    printf("\n3.pos");
    printf("\nEnter the choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
          printf("\n Enter the data:");
          scanf("%d",&data);
          insertBeg(data);
          traverse();
          break;
        case 2:
          printf("\n Enter the data:");
          scanf("%d",&data);
          insertEnd(data);
          traverse();
          break;

        case 3:
          printf("\n Enter the data:");
          scanf("%d",&data);
          printf("\nEnter the pos");
          scanf("%d",&pos);
          insertPos(data,pos);
          traverse();
          break;
        case 4:
         printf("\n key to search:");
         scanf("%d",&key);
         search(key);
         break;
          

          default:
          printf("\n invalid option");
          break;
    }
    }while(choice!=0);
    
}
