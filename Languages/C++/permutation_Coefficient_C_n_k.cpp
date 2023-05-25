#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int permutation_Coefficient(int n,int k)
{
    int fact[n+1];
    fact[0]=1;
    for(int i=1;i<=n;i++)
    fact[i]=i*fact[i-1];
    return fact[n]/fact[n-k];
}
int32_t main(){
fast
int n,k;
cin>>n>>k;
cout<<"P(n,k) : "<<permutation_Coefficient(n,k);
return 0;
}
/*Complexity Analysis:

P(n,k)  (n-k+1)*....*(n-2)*(n-1)*n

Time Complexity: O(n).

*/