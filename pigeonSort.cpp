#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long int
#define read(a) long long int a; cin>>a;
#define readstr(s) string s; cin>>s;
#define readarr(a,l) long long int a[l]={0}; for(ll i=0;i<l;i++) cin>>a[i];
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define ss second
#define readmtrx(i,j,a,b) ll arr[a][b]={0};for(ll i=0;i<a;i++)for(ll j=0;j<b;j++) cin>>arr[i][j];
#define v(pi) vector<ll>pi
#define vp(pi) vector<pair<ll,ll>>pi
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
#define pb(p) push_back(p)
#define mp make_pair
#include <cmath>
#include <map>
#define mi(lol) map<ll,ll>lol

void pigeonholeSort(ll arr[], ll n)
{
    ll min = arr[0], max = arr[0];
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    ll range = max - min + 1;
    vector<ll> holes[range];
    for (ll i = 0; i < n; i++)
        holes[arr[i]-min].push_back(arr[i]);
    ll index = 0;  // index in sorted array
    for (ll i = 0; i < range; i++)
    {
       vector<ll>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++]  = *it;
    }
}
int main()
{
    read(a);
    readarr(arr,a);

    pigeonholeSort(arr, a);

    cout<<"Sorted order is : ";
    for (int i = 0; i < a; i++)
        cout<<arr[i]<<" ";

    return 0;
}
