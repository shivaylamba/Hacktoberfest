#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n], sum=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        sum+=a[i];
	    }
	    if(sum%2==0 || sum==0){
	        cout<<"Yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}
