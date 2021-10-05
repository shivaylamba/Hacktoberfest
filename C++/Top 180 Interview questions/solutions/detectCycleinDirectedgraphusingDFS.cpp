bool isdfscycle(int node, vector<int>& vis, vector<int>& dfsvis
	, vector<int> adj[])
{
	vis[node] = 1;
	dfsvis[node]=1
	for(auto it : adj[node])
	{
		if(!vis[it])
			if(isdfscycle(it,vis,dfsvis,adj)) return true;
		else if(dfsvis[it])
			return true;
	}
	dfs[node] = 0;
	return false;
}
bool iscycle(int V, vector<int> adj[])
{
	vector<int> vis(V+1,0);
	vector<int> dfsvis(V+1,0);
	// for the cycle to be present both the nodes should be visited
	for(int i=1 ; i<=V; i++)
	{
		if(!vis[i])
		if(isdfscycle(i,vis,dfsvis,adj)) return true;
	}
	return false;
}