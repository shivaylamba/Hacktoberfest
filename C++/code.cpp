#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    if(n%7==0) {cout<<n<<endl; continue;}
	    int rem=n/7;
	    int a=rem*7;
	    int b=(rem+1)*7;
	    if((a-n)<=(b-n)) cout<<a<<endl;
	    else cout<<b<<endl;
	}
	return 0;
}
