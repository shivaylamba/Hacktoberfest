#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj; // Adjacency list to store edges and weights

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graph
    }

    // Dijkstra's algorithm to find the shortest path from source to all vertices
    void dijkstra(int source) {
        vector<int> dist(V, INF); // Initialize distances to infinity
        dist[source] = 0; // Distance from source to itself is 0

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the source vertex
        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    g.dijkstra(source);

    return 0;
}

/* 
  ***EXAMPLE TEST CASE****
  Enter the number of vertices and edges: 6 9
  Enter the edges and their weights:
  0 1 2
  0 2 4
  1 2 1
  1 3 7
  2 4 3
  4 5 2
  3 5 1
  3 2 5
  3 4 2
  Enter the source vertex: 0

  *****OUTPUT*****
  Shortest distances from source vertex 0:
  Vertex 0: 0
  Vertex 1: 2
  Vertex 2: 3
  Vertex 3: 7
  Vertex 4: 6
  Vertex 5: 8

*/
