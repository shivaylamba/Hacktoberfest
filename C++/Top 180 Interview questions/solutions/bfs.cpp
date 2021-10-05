vector<int> bfs(int v, vector<int> adj[])
{
	vector<int> bfsAnswer;
	vector<int> bfs(v+1,0);
	for(int i=1; i<=v;i++)
	{
		if(!vis[i])
		{
			// very important queue will be declared here
			queue<int> q;
			vis[i]=1;
			q.push(i);
			while(!q.empty())
			{
				int  node = q.front();
				q.pop();
				bfsAnswer.push_back(node);
				//push is to be done while popping
				for(auto it : ads[node])
				{
					if(!vis[it])
					{
						q.push(it);
						vis[it]=1;
					}
				}
			}
		}
	}
	return bfsAnswer;
}