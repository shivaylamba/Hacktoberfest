// Dijkstra's Algorithm in C++
// Finds the shortest path from a source node to all other nodes in a weighted graph.

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Pair to represent (distance, node)
typedef pair<int, int> pii;

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(int source, int n, vector<vector<pii>>& adj) {
    // Distance array to store the shortest distance to each node
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // Min-heap (priority queue) to pick the node with the smallest distance
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Visit each neighbor of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;

            // Relaxation step: if the distance to v can be minimized, update it
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Main function
int main() {
    int n, e, source;
    
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    // Adjacency list representation of the graph
    vector<vector<pii>> adj(n);
    
    cout << "Enter the edges (format: u v w, where u and v are nodes and w is the weight):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});  // Remove this line if graph is directed
    }

    cout << "Enter the source node: ";
    cin >> source;

    // Run Dijkstra's algorithm from the source node
    vector<int> shortestPaths = dijkstra(source, n, adj);

    cout << "Shortest distances from node " << source << " to all other nodes:" << endl;
    for (int i = 0; i < n; i++) {
        if (shortestPaths[i] == INT_MAX) {
            cout << "Node " << i << ": unreachable" << endl;
        } else {
            cout << "Node " << i << ": " << shortestPaths[i] << endl;
        }
    }

    return 0;
}
