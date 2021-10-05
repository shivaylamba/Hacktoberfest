bool solve(int i, vector<int>& vis, vector<int>& dfsvis, vector<int>& adj[])
{
vis[i] = true;
dfsvis[i] = true;
for(auto it : adj[i])
{
	if(!vis[it])
		 if(solve(it,vis,dfsvis,adj));
			return true;
	else if(dfsvis[it])
		return true;
}
dfsvis[i] = false;
return false;
}
bool iscyclic(int n, vector<int> adj[])
{
	vector<bool> vis,dfsvis(n+1,false);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			return solve(i,vis,dfsvis,adj);
	return false;
}