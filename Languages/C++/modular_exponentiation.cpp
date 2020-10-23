#include<bits/stdc++.h>
using namespace std;

long long power(long long x,long long y,long long m)
{
    long long ans=1;
    while(y>0)
    {
        if(y&1) ans=(ans*x)%m;
        x=(x*x)%m;
        y=y>>1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}