#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>& vis, vector<int>& tin,
	vector<int>& low, int& timer, vector<int> adj[], vector<int>& isArticulation) {

	vis[node] = 1; // mark the node as visited

	tin[node] = low[node] = timer++; // update the tin and low vector

	int child = 0; // number of child node has

	for (auto it : adj[node]) {

		if (it == parent) continue;

		if (!vis[it]) {
			
			dfs(it, node, vis, tin, low, timer, adj, isArticulation); // dfs call to connected nodes

			low[node] = min(low[node], low[it]);
			
			if (low[it] >= tin[node] && parent != -1) {  // if node can not be reached by other means
				isArticulation[node] = 1; // mark as articulation point
			}
			
			child++;
		}
		else {
			low[node] = min(low[node], tin[it]);
		}
	}
	if (parent == -1 && child > 1) {
		isArticulation[node] = 1;
	}
}

int main() {
	int n; // number of node
	int m; // number of edges
	cin >> n >> m;

	vector<int> adj[n];

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> tin(n, -1);  // for first time the node is reached
	vector<int> low(n, -1);  // for least time in which node can be reached
	vector<int> vis(n, 0);   // if node is visited once or not
	vector<int> isArticulation(n, 0);  // if node/point is a articulation or not

	int timer = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
		}
	}

	// Print all articulation points
	for (int i = 0; i < n; i++) {
		if (isArticulation[i]) {
			cout << i << " is a articulation point\n";
		}
	}

	return 0;
}
