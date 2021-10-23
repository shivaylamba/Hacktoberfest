#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
  cin>>n;
  map<int,int>mymap;
  int k,v;
  for(int i=0;i<n;i++){
  cin>>k>>v;
    mymap.insert(pair<int,int>(k,v));
  }
  int d;
  cin>>d;
  mymap.erase(d);
  for(auto x:mymap)
    cout<<x.first<<" "<<x.second<<endl;
	return 0;
}
