#include <iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* loc;
};

node *head = (struct node*)malloc(sizeof(struct node));
node *tail = (struct node*)malloc(sizeof(struct node));

struct node* insertNewValues(struct node* head, struct node* tail, int elementsNo){
	for(int i=0; i<elementsNo; i++){
		if(i==0){
			cout<<endl<<"Enter Data: ";
			cin>>head->data;
			tail = head;
		}
		else{
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			cout<<endl<<"Enter Data: ";
			cin>>temp->data;
			temp->loc = NULL;
			tail->loc = temp;
			tail = temp;
		}
	}
	return tail;
}

struct node* insertBegin(struct node *head){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	cout<<endl<<"Enter Data: ";
	cin>>temp->data;
	temp->loc=head;
	head=temp;
	cout<<head->data;
	return head;
}

void insertEnd(struct node *tail){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	tail->loc=temp;
	temp->loc=NULL;
	cout<<endl<<"Enter Data:";
	cin>>temp->data;
	tail = temp;
}

void insertRandom(struct node *head){
	
}

void deleteBegin(struct node *head){
	struct node *temp =  (struct node*)malloc(sizeof(struct node));
	temp = head;
	head=temp->loc;
}

void deleteEnd(struct node *head){
	struct node *temp =  (struct node*)malloc(sizeof(struct node));
	temp = head;
	while(temp->loc->loc!=NULL){
		temp=temp->loc;
	}
	temp->loc=NULL;
}

void deleteRandom(struct node *head){
	
}

void printList(struct node *head){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = head;
	while(temp->loc!=NULL){
		cout<<temp->data<<" ";
		temp=temp->loc;
	}
	cout<<temp->data;
}

int main(){
	
	int elementsNo;
	char choice = '0';
	cout<<"Enter no. of elements: ";
	cin>>elementsNo;
	tail = insertNewValues(head, tail, elementsNo);
	cout<<endl<<"HEAD="<<head->data;
	for(int i=0; choice!='9'; ){
		cout<<endl<<"**************MENU****************";
		cout<<endl<<"1. insert at beginning\t 2. insert at end\t 3. print\t 9.Exit";
		cout<<endl<<"Enter Choice: ";
		cin>>choice;
		switch(choice){
			case '1': head = insertBegin(head); 
				break;
			case '2': insertEnd(tail);
				break;
			case '3': printList(head);
				break;
			case '9': break; 
			default: cout<<endl<<"Invalid Input!!";
		}
	}
		
	return 0;
}
