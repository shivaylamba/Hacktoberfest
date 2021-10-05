vector<int> shortpath(int n ,vector<int> adj[])
{
	vector<int> dist(n+1,INT_MAX-1);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		int dist = dis[temp];
		for(it : adj[temp])
		{
			if(dist + 1 < dist[it]){
			dist[it] = dist + 1;
			q.push(it);
			}
		}
	}
	return dist;
}