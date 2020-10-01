#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
		if( n==0 )
		{
			cout<<"0";
			return 0;
		}
		if( n==1 || n==2 )
		{
			cout<<"1";
			return 0;
		}
		
	int arr[n];
	arr[0] = 1;
	arr[1] = 1;
	for( int i=2; i<n; i++ )
		arr[i] = arr[i-1]+arr[i-2];
	
	cout<<arr[n-1];
	return 0;
}
