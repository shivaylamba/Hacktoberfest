#include<iostream>
#include<list>
using namespace std;

class Queue{
	int cs;
	list<int> l;
	
public:
	Queue(){
		cs==0;
	}
	bool is_empty(){
		return cs==0;
		
	}
	void push(int data){
		l.push_back(data);
		cs=cs+1;
	}
	void pop(){
		cs--;
		l.pop_front();
	}
	int front(){
		return l.front();
		
	}
	
};
int main(){
	Queue q;
	for(int i=1;i<=10;i++){
		q.push(i*i);
	}
	q.pop();
	q.pop();
	
	while(!q.is_empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	
}
