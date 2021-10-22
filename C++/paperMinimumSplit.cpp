#include<iostream>
#include<algorithm>
using namespace std;
int n,m,mem[1000][1000];
int dp(int n,int m)
{
	if(n==0||m==0) return 0;
	if(n==m) return 1;
	if(mem[n][m]!=-1) return mem[n][m];
	int p=min(n,m),x=2e9;
	for(int i=1;i<=p;i++)
		x=min(x,min(1+dp(i,min(n,m)-i)+dp(min(n,m),max(n,m)-i),1+dp(i,max(n,m)-i)+dp(max(n,m),min(n,m)-i)));
	return mem[n][m]=x;
}
main()
{
	cin>>n>>m;
	for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) mem[i][j]=-1;
	cout<<dp(n,m);
}
