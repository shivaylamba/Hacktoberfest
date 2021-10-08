#include<bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long

struct SegTree{
	int size;
	vector<int> f;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		f.assign(2 * size, 0);
	}
	void set(int i, int x, int lx, int rx){
		if(rx - lx == 1){
			f[x] = 1;
			return;
		}
		int m = (lx + rx)/2;
		if(i < m)
			set(i, 2 * x + 1, lx, m);
		else
			set(i, 2 * x + 2, m, rx);
		f[x] = f[2 * x + 1] + f[2 * x + 2];
	}
	void set(int i){
		set(i, 0, 0, size);
	}
	int inversions(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return 0;
		else if(lx >= l && rx <= r) return f[x];
		int m = (lx + rx)/2;
		return inversions(l, r, 2 * x + 1, lx, m) + inversions(l, r, 2 * x + 2, m, rx);
	}
	int inversions(int i){
		return inversions(i, size, 0, 0, size);
	}
};
void solve(){
	int n, x;
	cin>>n;
	SegTree st;
	st.init(n);
	for(int i = 0; i < n; i++){
		cin>>x;
		st.set(x - 1);
		cout<<st.inversions(x)<<" ";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--)
		solve();
	return 0;
}
