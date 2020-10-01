#include <bits/stdc++.h>
using namespace std;

int sgtree[100006 * 5];
int arr[100005];

void build(int node, int start, int end) {
	if(start == end) {
		sgtree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build(2 * node + 1, start, mid);
	build(2 * node + 2, mid + 1, end);
	sgtree[node] = min(sgtree[2 * node + 1], sgtree[2 * node + 2]);
}

int query(int node, int start, int end, int l, int r) {
	if(r < start || end < l)
		return INT_MAX;
	if(l <= start && end <= r)
		return sgtree[node];
	int mid = (start + end) / 2;
	return min(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
}

void update(int node, int start, int end, int id, int val) {
	if(start == end) {
		arr[id] = val;
		sgtree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	if(start <= id && id <= mid) 
		update(2 * node + 1, start, mid, id, val);
	else
		update(2 * node + 2, mid + 1, end, id, val);
	sgtree[node] = min(sgtree[2 * node + 1], sgtree[2 * node + 2]);
}

int main(int argc, char const *argv[]) {
	int n, i, q;
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> arr[i];
	build(0, 0, n - 1);
	cin >> q;
	while(q--) {
		int tp, x, y;
		cin >> tp >> x >> y;
		if(tp == 1) {
			cout << query(0, 0, n - 1, x - 1, y - 1) << endl;
		} else if(tp == 2) {
			update(0, 0, n - 1, x - 1, y);
		}
	}
	return 0;
}