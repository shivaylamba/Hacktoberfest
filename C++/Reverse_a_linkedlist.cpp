#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* link;
	node(int val){
		this->data = val;
		this ->link = NULL;
	}
};
void insertattail(node* &head,int data){
	node* temp = new node(data);
	if(head==NULL){
		head = temp;
		return;
	}
	node* ptr = head;
	while(ptr->link!=NULL){
		ptr=ptr->link;
		
	}
	ptr->link=temp;
}
void reverse(node* &head){
	node* prev = NULL;
	node* curr = head;
	node* next = NULL;
	while(curr!=NULL){
		next = curr->link;
		curr->link=prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}
void print(node* &head){
	node* ptr = head;
	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr = ptr->link;
	}
	
}
int main(){
	node* head = NULL;
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		int x;
		cin>>x;
		insertattail(head,x);
	}
	print(head);
	cout<<endl;
	reverse(head);
	print(head);

}
