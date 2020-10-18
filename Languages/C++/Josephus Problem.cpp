#include <bits/stdc++.h>
using namespace std;


int josephus(int n, int k);

// Main Function
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}


/* The Recursive Josephus Function */
int jos(int n,int k)
{
    if(n==1)
  return 0;
  return (jos(n-1 , k) + k)%n;
}
int josephus(int n, int k)
{
  return jos(n,k)+1;
}



