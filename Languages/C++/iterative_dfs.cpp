#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the undirected graph
		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

// Perform iterative DFS on graph g starting from vertex v
void iterativeDFS(Graph const &graph, int v, vector<bool> &discovered)
{
	// create a stack used to do iterative DFS
	stack<int> stack;

	// push the source node into stack
	stack.push(v);

	// run till stack is not empty
	while (!stack.empty())
	{
		// Pop a vertex from stack
		v = stack.top();
		stack.pop();

		// if the vertex is already discovered yet,
		// ignore it
		if (discovered[v])
			continue;

		// we will reach here if the popped vertex v
		// is not discovered yet. We print it and process
		// its undiscovered adjacent nodes into stack
		discovered[v] = true;
		cout << v << " ";

		// do for every edge (v -> u)
		// we're using reverse iterator (Why?)
		for (auto it = graph.adjList[v].rbegin();
				  it != graph.adjList[v].rend(); ++it)
		{
			int u = *it;
			if (!discovered[u])
				stack.push(u);
		}
	}
}

// Depth First Search (DFS) Iterative Implementation
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		// Notice that node 0 is unconnected node
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
		// , {6, 9} // introduce cycle
	};

	// Number of nodes in the graph (0-12)
	int N = 13;

	// create a graph from given edges
	Graph graph(edges, N);

	// stores vertex is discovered or not
	vector<bool> discovered(N);

	// Do iterative DFS traversal from all undiscovered nodes to
	// cover all unconnected components of graph
	for (int i = 0; i < N; i++)
		if (discovered[i] == false)
			iterativeDFS(graph, i, discovered);

	return 0;
}
