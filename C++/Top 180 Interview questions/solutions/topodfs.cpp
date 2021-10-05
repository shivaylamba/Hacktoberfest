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