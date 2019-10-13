#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);//remove this line for directed graph
}

void BFS(vector<int> adj[],int V){
    bool visited[V+1];

    for (int i = 1; i < V+1; i++)
        visited[i] = false;
    
    queue<int> q;
    int s = 1; //our source vertex will be 1
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        visited[u] = true;
        cout << q.front() << " ";
        q.pop();

        for(int v: adj[u]){
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    int V = 6;
    vector<int> adj[V + 1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    BFS(adj, V);
    
    return 0;
}
