#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t>0)
	{
	    t--;
	    int e,n; cin>>e>>n; //e=no of eggs and n=no of floors
	    vector<vector<int>> v(e+1,vector<int> (n+1,0));
	    int res;
	    for(int i=1;i<=e;i++)
	    {
	        v[i][0]=0; v[i][1]=1;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        v[1][i]=i;
	    }
	    for(int i=2;i<=e;i++)
	    {
	        for(int j=2;j<=n;j++)
	        {   v[i][j]=INT_MAX;
	            for(int x=1;x<=j;x++)
	            {
	                res=1+max(v[i-1][x-1],v[i][j-x]);
	                v[i][j]=min(res,v[i][j]);
	            }
	        }
	    }
	    cout<<v[e][n]<<endl;
	}
	return 0;
}
