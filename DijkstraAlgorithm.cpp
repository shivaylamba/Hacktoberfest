#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to implement Dijkstra's Algorithm
void dijkstra(int vertices, int src, vector<vector<pair<int, int>>> &adj) {
    // Create a distance vector and initialize all distances as infinity
    vector<int> dist(vertices, INT_MAX);
    dist[src] = 0; // Distance to source is 0

    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // Skip if this path is not better than the already found one
        if (currentDist > dist[currentNode])
            continue;

        // Explore all neighbors
        for (auto &neighbor : adj[currentNode]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (dist[nextNode] > currentDist + edgeWeight) {
                dist[nextNode] = currentDist + edgeWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Print the shortest distances
    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << " : ";
        if (dist[i] == INT_MAX)
            cout << "Unreachable";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> adj(vertices);

    cout << "Enter edges (u v w) where u and v are nodes and w is weight:\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove this line if the graph is directed
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(vertices, src, adj);

    return 0;
}