//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = long long int;

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Disjoint set union find 
vector<int> dsuf; 

int find(int u){ //finds the leader of the set. 
	std::vector<int> vec;
	while(dsuf[u]>0){
		vec.push_back(u); //save elements for compressing paths.
		u=dsuf[u];
	}
	for(int i=0;i<vec.size();i++){
		dsuf[vec[i]]=u; // compress paths.
	}
	return u;
}


void union_op(int u,int v){ //places the two elements in the same set. 
	int p1=find(u);
	int p2=find(v);
	if(p1!=p2)
		dsuf[p2]=p1;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    jets();
    int n,q;
    cin>>n>>q;
    dsuf.resize(100002,-1);// initially every element is present in it's own set.
    while(q--){
    	string s;
    	cin>>s;
    	if(s=="union"){
    		int u,v;
    		cin>>u>>v;
    		union_op(u,v);
    	}else{
    		int u,v;
    		cin>>u>>v;
    		int p1=find(u);
    		int p2=find(v);
    		if(p1==p2){
    			cout<<"YES";
    		}
    		else{
    			cout<<"NO";
    		}
    		cout<<endl;
    	}
    }
    
    return 0;
}