/*The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to calculate span of stock’s price for 
all N days. You are given an array of length N, where ith element of array denotes the price of a stock on ith. Find the span of stock's price on ith day, for 
every 1<=i<=N.
A span of a stock's price on a given day, i, is the maximum number of consecutive days before the (i+1)th day, for which stock's price on these days is less 
than or equal to that on the ith day.*/

#include<iostream>
#include<stack>
using namespace std;

void stock_span(int prices[],int n,int span[]){
	stack<int>s; //indices of the day
	s.push(0);
	span[0]=1;
	//loop for the rest of the days
	for(int i=1;i<=n-1;i++){
		int current_price=prices[i];
		//topmost element that is highest from the current prices
		while(!s.empty() and prices[s.top()]<=current_price){
			s.pop();
		}
		if(!s.empty()){
			int prev_highest=s.top();
			span[i]=i-prev_highest;
		}
		else{
			span[i]=i+1;
		}
		//push this element into the stack
		s.push(i);
	}
}
int main(){
	int prices[]={100,80,60,70,60,75,85};
	int n=sizeof(prices)/sizeof(int);
	int span[10000]={0};
	stock_span(prices,n,span);
	for(int i=0;i<n;i++){
		cout<<span[i]<<" ";
	}
	return 0;
}
