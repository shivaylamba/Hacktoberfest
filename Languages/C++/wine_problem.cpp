#include<iostream>
using namespace std;

int wine(int *a,int i,int j,int day){
	if(i>j){
		return 0;
	}

	int op1=a[i]*day+wine(a,i+1,j,day+1);
	int op2=a[j]*day+wine(a,i,j-1,day+1);
	int ans=max(op1,op2);
	return ans;
}

int topdown(int *a,int i,int j,int dp[][100],int day){
	if(i>j){
		dp[i][j]=0;
		return dp[i][j];
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int op1=a[i]*day+topdown(a,i+1,j,dp,day+1);
	int op2=a[j]*day+topdown(a,i,j-1,dp,day+1);
	dp[i][j]=max(op1,op2);
	return dp[i][j];
}

int bottomup(int *a,int n){
	int dp[100][100]={0};
	int day=n;
	for(int i=0;i<n;i++){
		dp[i][i]=a[i]*day;
	}
	day--;

	for(int len=2;len<=n;len++){
		int i=0;
		int maxi=n-len;
		while(i<=maxi){
			int j=i+len-1;
			int op1=a[i]*day+dp[i+1][j];
			int op2=a[j]*day+dp[i][j-1];
			dp[i][j]=max(op1,op2);
			i++;
		}
		day--;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	return dp[0][n-1];
}

int main(){
	int a[]={2,3,5,1,4};
	int n=sizeof(a)/sizeof(int);
	int dp[100][100];
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=-1;
		}
	}

	cout<<topdown(a,0,n-1,dp,1)<<endl;
	cout<<bottomup(a,n)<<endl;
	cout<<wine(a,0,n-1,1)<<endl;      //O(2^n)

	return 0;
}