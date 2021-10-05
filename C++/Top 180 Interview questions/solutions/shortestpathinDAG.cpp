// we can use stack
// so we push elements in top
int toposort(int i, stack<int>& topo, vector<int>& vis, int adj[])
{
	vis[i]= true;
	for(auto it: adj[i])
	{
		if(!vis[it])
			topo(it,topo,vis,adj);
	}
	topo.push(it);
}
vector<int> solve(int n , vector<int> adj[])
{
	vector<int> v;
	stack<int> topo;
	vector<int> vis(n,0);
	for(int i = 0 ; i < n ; i++)
	{
		if(!vis[i])
			toposort(i,topo,vis,adj);
	}
	while(!st.empty())
	{
		v.pb(st.top());
		st.pop();
	}
	return v;
}

int main()
{
	// first need topo sort
	int n;
	vector<pair<int,int>> adj[];
	// for storing weights
	vector<int> v;
	vector<int> dist(n,INT_MAX-1);
	stack<int> s; // has topo sort
	v = solve(n,adj);
	dist[0] = 0;
	while(!s.empty())
	{
		int node = s.top();
		int distance = dist[node];
		s.pop();
		if(dist[node]!=INT_MAX-1)
		{
			for(auto it : adj[node])
			{
				if(distance + it.s < dist[it.f])
					dist[it.f] = distance + it.s;
			}
		}
	}
	return dist;

}