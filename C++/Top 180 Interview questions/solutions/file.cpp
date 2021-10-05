// @author: Laksh Sadhwani
// Github : https://github.com/Laaaaksh
// Code : next round
/* n<=10 - O(n!) 
   n<=20 - O(2^n)
   n<=500 - O(n^3)
   n<=5000 - O(n^2)
   n<=10^6 - O(nlogn) and O(n)
   n is large - O(1) or O(log(n))*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back;
#define mp make_pair;
#define f first;
#define s second;
// random_shuffle(v.begin(),v.end());
#define rep(i,a,b) for(int i = a; i<=b;i++)
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
// #ifndef ONLINE_JUDGE

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
// #endif
// string x;
// getline(cin,x);
// while(cin >> x)
// {

// }
// int128_t temp;
   int n , k;
   cin  >> n >> k;
   int arr[n];
   rep(i,0,n-1)
      cin >> arr[i];
   int i = 0;
   int count = 0;
   while(i < n)
   {
      if(arr[i] >= arr[k-1] && arr[i] > 0)
         count++;
      i++;
   }
   cout << count;
}