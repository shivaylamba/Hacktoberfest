//-----------जय श्री राम-----------




#include <bits/stdc++.h>

using namespace std;

#define int long long

#define all(x) (x).begin(), (x).end()

#define pb(x) push_back(x)

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){
	//start
    int n;cin>>n;
    int cnt=0;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	int x=arr[i];
    	while(x%2==0){
    		x/=2;
    		cnt++;
    	}
    }
    vector<int> v;
    for(int i=2;i<=n;i+=2){
    	int temp=0;
    	int j=i;
    	while(j%2==0){
    		temp++;
    		j/=2;
    	}
    	v.pb(temp);
    }
    sort(all(v));
    reverse(all(v));
    int ans=0;
    for(auto&x:v){
    	if(cnt>=n){
    		break;
    	}
    	cnt+=x;
    	ans++;
    }
	
	if(cnt>=n)cout<<ans;
	else cout<<-1;
}
signed main(){
    fast;
    int t;cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}
