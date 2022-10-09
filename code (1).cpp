#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--){
	    int n, k;
	    vector<long long> l, r, e;
	    cin>>n;
	    cin>>k;
	    vector<pair<long long, pair<long long, long long>>> info;
	    for(int i=0;i<n;i++){
	        long long x;
	        cin>>x;
	        l.push_back(x);
	        
	    }
	    for(int i=0;i<n;i++){
	        long long x;
	        cin>>x;
	        r.push_back(x);
	    }
	    for(int i=0;i<n;i++){
	        long long x;
	        cin>>x;
	        e.push_back(x);
	    }
	    for(int i=0;i<n;i++){
	        info.push_back({e[i], {l[i], r[i]}});
	    }
	    sort(info.begin(), info.end());
	    long long ans=0;
	    for(auto x: info){
	        if(x.second.first!=0) ans+=x.first*x.second.first, k-=x.second.first, 
	        x.second.second-=x.second.first;
	        x.second.first=0;
	    }
	    
	        for(auto x: info){
	            if(x.second.second<=k)
	            {
	                ans+=(x.second.second*x.first);
	                k-=x.second.second;
	            }
	            else{
	                ans+=(k*x.first);
	                k=0;break;
	            }
	        }
	        cout<<ans<<endl;
}
	    
	
	return 0;

}
