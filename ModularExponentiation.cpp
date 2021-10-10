//Have A Good Day Visitor:)
//Author: Saksham Goel
#include<bits/stdc++.h>
#define MOD 1000000007
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long int
#define lli long long int
using namespace std;
int modexpo(int n,int pow){
	if(pow==1)
	return n;
	int temp=modexpo(n,pow/2)%MOD;//Logn complexity 
	if(pow%2==0)
		return (temp*temp)%MOD;
	else
		return (temp*temp*n)%MOD;
}
int32_t main(){
	int n;
	cout<<"Enter a number\n";
	cin>>n;
	cout<<"Enter the power you want to raise it to: \n";
	int pow;
	cin>>pow;
	cout<<modexpo(n,pow);//Answer will be modulus 10^9+7
	return 0;
}
