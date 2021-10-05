// @author: Laksh Sadhwani
// Github : https://github.com/Laaaaksh
// Code : (__Name__)
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
#define rep(i,a,b) for(int i = a; i<=b;i++)
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// string x;
// getline(cin,x);
// while(cin >> x)
// {

// }
// int128_t temp;
int n;
int best = 0;
// minimum
cin >> n;
vi v;
rep(i,0,n-1)
{
   cin >> v[i];
}
rep(i,0,n-1)
{
   rep(j,i,n-1)
   {
      int sum = 0;
      rep(k,i,j)
      {
         sum+=v[k];
      }
      best = max(best,sum);
   }
}
cout << best << "\n";
return 0;
}