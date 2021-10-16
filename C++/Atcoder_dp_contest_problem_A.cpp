#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int n,i;
	cin>>n;
	vector<int>a(n+1);
	for(i=1;i<=n;i++)
	cin>>a[i];
	int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[1]=0;dp[2]=abs(a[2]-a[1]);
    for(i=3;i<=n;i++)
    {
    	dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n];
	return 0;
}