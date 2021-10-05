
bool ifiscycle(int node, int parent, vector<int>& vis, vector<int> adj[])
{
	vis[node] = 1;
	// here we aren't pushing anything so
	for(auto it : adj[node])vis{
		if(!vis[it])
			if(iscycle(it,node,vis,adj)) return true;
		else if(it!=parent) return true;
	}
	return false;
}
bool iscycle(int V, vector<int> adj[])
{
	vector<int> vis[V+1];
	for(int i = 1 ; i <=V;i++)
	{
		if(ifiscycle(i,-1,vis,adj)) return true;
	}
	return false;
}