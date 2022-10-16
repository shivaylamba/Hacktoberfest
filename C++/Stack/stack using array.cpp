#include<iostream>
using namespace std;
#define SIZE 5
int A[SIZE];
int top=-1;

bool isempty(){
	if(top==-1){
		return true;
		
	}
	return false;
}
void push(int value){
	if(top==SIZE-1){
		cout<<"stack is full"<<endl;
	}
	else{
		top++;
		A[top]=value;
	}
}
void pop(){
	if(isempty()){
		cout<<"stack is empty"<<endl;
	}
	else{
		top--;
	}
}
void show_top(){
	if(isempty()){
		cout<<"stack is empty"<<endl;
	}
	else{
		cout<<"element at top is : "<<A[top]<<endl;
	}
}
void display_stack(){
	if(isempty()){
		cout<<"stack is empty"<<endl;
	}
	else{
		for(int i=0;i<=top;i++){
			cout<<A[i]<<" ";
		}
	}
}
int main(){
	int A[SIZE];
    int top=-1;
	push(2);
	push(3);
	push(4);
	push(5);
	
	display_stack();
	cout<<endl;
	pop();
	display_stack();
	cout<<endl;
	show_top();
	return 0;
}
