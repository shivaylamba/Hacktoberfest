#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int temp) {
	if(s.empty()) {
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s,temp);
	s.push(val);
	return;
}

void reverse(stack<int> &s) {
	if(s.empty()) {
		return;
	}
	int temp=s.top();
	s.pop();
	reverse(s);
	insert(s,temp);
	return;
}

void print(stack<int> s) {
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

int main() {
	stack<int> s,temp;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	temp=s;
	print(temp);
	reverse(s);
	temp=s;
	print(temp);
	return 0;
}
