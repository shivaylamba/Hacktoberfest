//author: kvv1618
#include <bits/stdc++.h>
using namespace std;
void tdfs(int n,vector<vector<float> >v,int dp[],int i,float t){
    dp[i]=1;
    for(int j=0;j<n;j++)
    {
        if(dp[j]==0&&v[i][j]>t)
        {
            tdfs(n,v,dp,j,v[i][j]);
        }
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    float a[n];
	    vector< vector<float> >v(n,vector<float>(n,0.0));
	    for(int i=0;i<n;i++)
	    {
	        float x;
	        cin>>x;
	        a[i]=float(x);
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(a[j]-a[i]!=0)
	            {
	                float t=(float(j)-float(i))/(float(a[i])-float(a[j]));
	                if(t>0)
	                {
	                    v[i][j]=t;
	                    //cout<<t<<endl;
	                }
	            }
	        }
	    }
	    vector<int>ans;
	    for(int i=0;i<n;i++)
	    {
	        int dp[n]={0};
	        int c=0;
	        tdfs(n,v,dp,i,0);
	        for(int j=0;j<n;j++)
	        {
	            if(dp[j]==1)
	            c++;
	        }
	        ans.push_back(c);
	    }
	    sort(ans.begin(),ans.end());
	    cout<<ans[0]<<" "<<ans[ans.size()-1]<<endl;
	}
	return 0;
}
