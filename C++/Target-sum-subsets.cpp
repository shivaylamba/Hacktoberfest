#include<bits/stdc++.h>
using namespace std;
void ts(vector<int>v,int ind,int target,int summ,string ans,int n)
{
    if(summ>target)
    return;
    
  if(ind==n)
  {
      if(target==summ)
      {
          cout<<ans<<"."<<endl;
      }
      return;
  }
    ts(v,ind+1,target,summ+v[ind],ans+to_string(v[ind])+", ",n);
    ts(v,ind+1,target,summ,ans,n);
}
int main()
{
    int n,t,i=0;
    cin>>n;
    vector<int>v;
    v.resize(n);
    while(i<n)
    {
        cin>>v[i];
        i++;
    }
    cin>>t;
    ts(v,0,t,0,"",n);
}
