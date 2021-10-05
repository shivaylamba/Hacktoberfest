// can only be applied to directed acyclic graphhs
// in an undirected graph edge cannot be specified
// in case of cycle you cannot have topo sort as well
vector<int> toposort(int V , vector<int> adj[])
{
	vector<int> topo;
	queue<int> q;
	vector<int> indegree(V,0);
	for(int i=1 ; i<=V;i++)
	{
		for(auto it : adj[i])
			indegree[it]++;
	}
	for(int i = 1;i<=V;i++)
	{
		if(indegree[i]==0)
			q.push_back(i);
	}
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		v.push_back(node);
		for(auto it : adj[node])
		{
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}
	return topo;
}