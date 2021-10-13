#include<bits/stdc++.h>
using namespace std;
int main(){
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin>>t;
	
	while(t--){
int n,count=0;
cin>>n;
// cout<<n<<endl;
int arr[n+1];
 for (int i = 0; i < n; ++i)
 {
 	cin>>arr[i];
 	
 	
 }

 for (int i = 0; i < n; ++i)
 {
 	
 	if (arr[i]>arr[i-1])
 	{
 		count++;
 	}
 	// else break;
 }
 int total=n-count;
 cout<<total<<endl;

	}
}
