//Adesh kumar//
//wilderbeast_//
#include<bits/stdc++.h>
using namespace std;
#define  pb    push_back
#define  mp    make_pair
#define  fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define  FOR(i,j,k,in)  for(int i=j;i<=k;i+=in)
#define  RFOR(i,j,k,dc) for(int i=j;i>=k;i-=dc)
#define  ff  first
#define  ss  second
#define  T   int t;cin>>t;while(t--)
#define  mem(a,b)  memset(a,(b),sizeof(a))
#define  all(c)   c.begin(),c.end()
#define  rall(c)  c.rbegin(),c.rend()
#define  FORIT(it,m)  for(it=m.begin();it!=m.end();it++)
#define  mod  1000000007
#define  maxin  INT_MAX
#define  minin  INT_MIN
#define  sz(cnt) (int)cnt.size()
#define  in(c,x)     c.find(x)!=c.end()
#define  bits  __builtin_popcount
#define  gcd   __gcd
typedef  long long int LL;
typedef  long int L;
typedef  vector<int>VI;
typedef  vector<string>VS;
typedef  vector<LL>VLL;
typedef  map<int,int>MPII;
typedef  map<char,int>MPCI;
typedef  set<int>STI;
typedef  multiset<int>MSTI;
typedef  pair<int,int>PII;
LL power(LL a,LL b,LL m){
	LL res = 1;
	while(b>0){
		if(b%2==1){
		res = (res%m * a%m)%m;
		}

		a = (a%m * a%m)%m;
		b/=2;	
	}
	return res;
}
//********************TEMPLATES*******************//
int main(){
	fast;
	T{
			
	}
return 0;
}
