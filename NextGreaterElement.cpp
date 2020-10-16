#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	stack<int> s;
	int a1[n]; 
	for (int i=n-1;i>=0;i--) 
	{
		while (!s.empty() && s.top()<=a[i]) 
			s.pop();
		if (s.empty())
			a1[i]=-1;		 
		else
			a1[i]=s.top();
		s.push(a[i]);
	}
	for(int i=0;i<n;i++) 
		cout<<a[i]<<" ---> "<<a1[i]<<endl; 
	return 0; 
} 
