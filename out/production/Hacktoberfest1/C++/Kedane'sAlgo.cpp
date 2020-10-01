#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	long long int n;
	cin >> n;
	
	long long int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	
	long long int max_overall = -1000, max_here = 	0;
	
	for(int i=0; i<n; i++)
	{
		max_here = max_here + arr[i];
		
		if(max_here > max_overall)
		max_overall = max_here;
		
	    if(max_here < 0)
		max_here = 0;
	}
	
	cout << max_overall << endl;
	
    }
}
