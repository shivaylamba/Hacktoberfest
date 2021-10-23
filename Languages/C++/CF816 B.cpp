//CF
//Karen and Coffee  
//https://codeforces.com/contest/816/problem/B

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector <int> v(2000005,0);
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v[a]++;
        v[b+1]--;
    }
    for(int i=1;i<=2000002;i++)
    {
        v[i]=v[i]+v[i-1];
    }
    int c=0;
    for(int i=1;i<=2000002;i++)
    {
        if(v[i]>=k)
            {
                c++;
                v[i]=c;

            }
            else
            v[i]=c;
    }
//    for(int i=90;i<=110;i++)
//    {
//        cout<<i<<" "<<v[i]<<endl;
//    }
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        cout<<v[b]-v[a-1]<<endl;
    }

}


