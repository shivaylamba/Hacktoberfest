#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>>adj;
    public:
    void addEdge(T u, T v, bool bidir = true){
              adj[u].push_back(v);
              if(bidir){
                  adj[v].push_back(u);
              }
        }

    void dfshelper(T node, map<T,bool> &visited, list<T> &ordering){
        cout<<node<<endl;
        visited[node] =  true;
        for( auto neighbour: adj[node]){
            if(!visited[neighbour])
              dfshelper(neighbour,visited,ordering);
        }
        ordering.push_back(node);
    }
    void dfs(T src){
        map<T,bool>visited;
        dfshelper(src,visited);
    }

    void TopologicalSortUsingDFS(T src){
        map<T,bool>visited;
        list<T>ordering;

        for(auto neighbour: adj[src]){
            if(!visited[neighbour]){
                dfshelper(neighbour,visited,ordering);
            }
        }
        
        for(auto ans: ordering){
            cout<<ans<<":"; 
        }
    }
};
int main() {
    
    Graph<string>g;
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Modi","Trump",false);
    g.addEdge("Modi","Yogi",false);
    g.TopologicalSortUsingDFS("Putin");
}
