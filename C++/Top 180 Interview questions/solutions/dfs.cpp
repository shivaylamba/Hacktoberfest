void dfs(int node, vector<int>& vis , vector<int> &adj[], vector<int>& dfsAnswer )
{
	dfsAnswer.push_back(node);
	// second we mark it as visited
	vis[node] = 1;
	for(auto it : adj[node])
	{
		if(!vis[it])
			dfs(it,vis,adj,dfsAnswer);
	}
}

vector<int> dfsofGraph(int V, vector<int>adj[])
{
	vector<int> dfsAnswer;
	vector<int> vis(V+1,0);
	for(int i = 1 ; i <=V ; i++)
	{
		if(!vis[i])
		// need to call dfs for all the components seperately
		dfs(i,vis,adj,dfsAnswer);
	}
	return dfsAnswer;
}