/* Read input from STDIN. Print your output to STDOUT*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a[10000],temp;
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		getline(cin,a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i] > a[j])
          {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
          }
		}
	}
	for(int i=1;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<a[n];
	return 0;
}
