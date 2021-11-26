#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t!=0)
	{
		t--;
		int n,k,x,y;
		cin>>n>>k>>x>>y;//x-current,y-yours
		string ans="NO";
		for(int i=0;i<n;i++)
		{
			if((x+k)%n==y)
			{
				ans="YES";
				break;
			}
			else
			{
				x=(x+k)%n;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
