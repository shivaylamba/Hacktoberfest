#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);//remove this line for directed graph
}

void DFSUtil(vi adj[],int i, vector<bool> &visited){
    visited[i] = true;
    cout << i << " ";
    for (int u = 0; u < adj[i].size(); u++)
    {
        if(visited[adj[i][u]] == false){
            DFSUtil(adj,adj[i][u],visited);
        }
    }
}

void DFS(vi adj[],int V){
    vector<bool> visited(V,false);
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false){
            DFSUtil(adj, i, visited);
        }
    }
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    int V = 5;
    vi adj[V];    
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 2, 4); 
    DFS(adj, V); 
    return 0;
}
