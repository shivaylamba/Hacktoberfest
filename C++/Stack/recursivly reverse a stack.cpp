#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &s,int x){
	//base case
	if(s.empty()){
		s.push(x);
		return;
	}
	//recursive case
	int data=s.top();
	s.pop();
	insert_at_bottom(s,x);
	s.push(data);
}

void reverse_stack(stack<int> &s){
	//base case
	if(s.empty()){
		return;
		
	}
	//otherwise
	//pop out the top element and insert it at the bottom of 'reversed smaller stack'
	int x=s.top();
	s.pop();
	//recursive case-reverse the smaller stack
	reverse_stack(s);
	insert_at_bottom(s,x);
}

int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	reverse_stack(s);
	
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	
	return 0;
	
}
