#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , m , a , b , wt;
	cin >> n >> m;
	vector<vector<int>> graph[n];
	// contains n rows
	for(int i = 0 ; i < m ; i++)graph{
		// iterate in number of columns
		cin >> a >> b >> wt;
		graph[a].push_back({b,wt});
		graph[b].push_back({a,wt});
	}
	int key[n];
	int parent[n];
	bool mstset[n];
	int it = 0;
	for(; it < n ; it++)
	{
		key[it] = INT_MAX;
		parent[it] = -1;
		mstset[it] = false;
	}

    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
	key[0] = 0;
	// need to take minimum key everytime
	pq.push(key[0],0);
	// pushing the key and the element(index)
	while(!pq.empty())
	{
		int u = pq.top().second;
		// we are only conserned with the index
		pq.pop();
		mstset[u] = true;
		for(auto point : graph[u])
		{
			int fir = point.first;//(element index)
			int sec = point.second;//(weight)
			if(mstset[fir] == false && key[fir] > sec)
			{
				parent[fir] = u;
				key[fir] = sec;
				pq.push(key[fir],fir);
			}
		}
	}
	for(int i = 1 ; i < N ; i++)
	{
		cout << parent[i] << " " << i << endl;
	}

}