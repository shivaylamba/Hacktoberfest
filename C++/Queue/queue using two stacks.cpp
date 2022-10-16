#include<iostream>
#include<stack>
using namespace std;

class queue{
	stack<int> s1,s2;
public:
	void push(int x){
		s1.push(x);
	}
	void pop(){
		if(s1.empty()){
			return;
		}
		while(s1.size()>1){
			int element=s1.top();
			s2.push(element);
			s1.pop();
		}
		s1.pop();
		while(!s2.empty()){
			int element=s2.top();
			s1.push(element);
			s2.pop();
		}
	}
	int front(){
		while(s1.size()>1){
			int element=s1.top();
			s2.push(element);
			s1.pop();
			
		}
		int element=s1.top();
		s1.pop();
		s2.push(element);
		return element;
		while(!s2.empty()){
			int element=s2.top();
			s1.push(element);
			s2.pop();
		}
	}
	bool empty(){
		return s1.size()==0;
	}
};
int main(){
	queue q;
	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(5);
	
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
	
}