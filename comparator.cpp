#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int>b )
{
  if(a.first!= b.first)
  return a.first<b.first;
  else
  return b.second<a.second;
  

}

int main()
{
    vector<pair<int,int>>v={{4,2},{63,7},{25,1},{25,2}};
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<endl;
}