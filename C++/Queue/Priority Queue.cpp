#include<iostream>
#include<queue>
using namespace std;
int main(){
	priority_queue<int>pq;//Max Heap
	//change the priority
	//priority_queue<int,<vector<int>,greater<int>>  Min Heap
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int no;
		cin>>no;
		pq.push(no); //insert in heap in O(log(N)) time
		
	}
	//remove the elements from the heap
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
		
	}
}

