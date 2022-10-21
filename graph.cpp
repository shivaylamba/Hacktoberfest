// C++ program to find the longest cable length
// between any two cities.
#include<bits/stdc++.h>
using namespace std;

// visited[] array to make nodes visited
// src is starting node for DFS traversal
// prev_len is sum of cable length till current node
// max_len is pointer which stores the maximum length
// of cable value after DFS traversal
void DFS(vector< pair<int,int> > graph[], int src,
		int prev_len, int *max_len,
		vector <bool> &visited)
{
	// Mark the src node visited
	visited[src] = 1;

	// curr_len is for length of cable from src
	// city to its adjacent city
	int curr_len = 0;

	// Adjacent is pair type which stores
	// destination city and cable length
	pair < int, int > adjacent;

	// Traverse all adjacent
	for (int i=0; i<graph[src].size(); i++)
	{
		// Adjacent element
		adjacent = graph[src][i];

		// If node or city is not visited
		if (!visited[adjacent.first])
		{
			// Total length of cable from src city
			// to its adjacent
			curr_len = prev_len + adjacent.second;

			// Call DFS for adjacent city
			DFS(graph, adjacent.first, curr_len,
				max_len, visited);
		}

		// If total cable length till now greater than
		// previous length then update it
		if ((*max_len) < curr_len)
			*max_len = curr_len;

		// make curr_len = 0 for next adjacent
		curr_len = 0;
	}
}

// n is number of cities or nodes in graph
// cable_lines is total cable_lines among the cities
// or edges in graph
int longestCable(vector<pair<int,int> > graph[],
										int n)
{
	// maximum length of cable among the connected
	// cities
	int max_len = INT_MIN;

	// call DFS for each city to find maximum
	// length of cable
	for (int i=1; i<=n; i++)
	{
		// initialize visited array with 0
		vector< bool > visited(n+1, false);

		// Call DFS for src vertex i
		DFS(graph, i, 0, &max_len, visited);
	}

	return max_len;
}

// driver program to test the input
int main()
{
	// n is number of cities
	int n = 6;

	vector< pair<int,int> > graph[n+1];

	// create undirected graph
	// first edge
	graph[1].push_back(make_pair(2, 3));
	graph[2].push_back(make_pair(1, 3));

	// second edge
	graph[2].push_back(make_pair(3, 4));
	graph[3].push_back(make_pair(2, 4));

	// third edge
	graph[2].push_back(make_pair(6, 2));
	graph[6].push_back(make_pair(2, 2));

	// fourth edge
	graph[4].push_back(make_pair(6, 6));
	graph[6].push_back(make_pair(4, 6));

	// fifth edge
	graph[5].push_back(make_pair(6, 5));
	graph[6].push_back(make_pair(5, 5));

	cout << "Maximum length of cable = "
		<< longestCable(graph, n);

	return 0;
}
