#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 4
char item[10];
char *d_q[MAX];
int f=-1;
int r=-1;
void display(){
	int i;
	i=f;
	if(f<=r)
	{
		while(i<=r)
		printf("%s\t",d_q[i++]);
			printf("\n");
	}
	else
	{
		while(i<=MAX-1)
		printf("%s\t",d_q[i++]);
		
		i=0;
		while(i<=r)
		printf("%s\t",d_q[i++]);
		printf("\n");
		
	}}
	
	int isempty(){
	if(f==-1&&r==-1)
		return 1;
		
	else return 0;
	
}

int isfull(){
	if(f==0&&r==MAX-1||f==r+1)
	return 1;
	
	else
	return 0;	
}


void insert_at_front(char item []){
	if(f==-1&&r==-1)
	{
		f++;
		r++;
	}
  	else if(f==0)
	f=MAX-1;
	else
	f--;
	d_q[f]=(char*)malloc(sizeof(char)*strlen(item));
	strcpy(d_q[f],item);
	printf("\tf=%d\tr=%d\n",f,r);
	}
	

void insert_at_rear(char item []){
	if(f==-1&&r==-1)
	{
		f++;
		r++;
	}
  	else if(r==MAX-1)
	r=0;
	else
	r++;
	d_q[r]=(char*)malloc(sizeof(char)*strlen(item));
	strcpy(d_q[r],item);
	printf("\tf=%d\tr=%d\n",f,r);
	}
	
	void delete_from_front(){
	printf("The item deleted is %s",d_q[f]);
	if(f==r)
	f=r=-1;
	else if(f==MAX-1)
	f=0;
	else 
	f++;
	printf("\tf=%d\tr=%d\n",f,r);
}	

void delete_from_rear(){
	printf("The item deleted is %s",d_q[r]);
	if(f==r)
	f=r=-1;
	else if(r==0)
	r=MAX-1;
	else 
	r--;
	printf("\tf=%d\tr=%d\n",f,r);
}

int main()
{
	int ch,i;
	while(1)
	{
		printf("1.-Insert\t");
		printf("2.-Delete\t");
		printf("3.-Display\t");
		printf("4.-Exit\t");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			if(isfull())
			{
				printf("Deque Overflow");
				printf("\tf=%d\tr=%d\n",f,r);
				break;
			}
			else
			{
				int a;
				printf("1.Insert at front\t2.Insert at rear\t");
				scanf("%d",&a);
				printf("Enter the string\t");
				scanf("%s",&item);
				if(a==1)
					insert_at_front(item);
				else
					insert_at_rear(item);
			}
			break;
			
		case 2:
			if(isempty()){
			printf("Deque Underflow");
			printf("\tf=%d\tr=%d\n",f,r);}
			
			else{
				int a;
				printf("1.Delete from front\t2.Delete from rear\t");
				scanf("%d",&a);
				if(a==1)
					delete_from_front(item);
				else
					delete_from_rear(item);}
			break;
			
		case 3:
			display();
			break;
			
		case 4:
			exit(1);
	}
	}}
