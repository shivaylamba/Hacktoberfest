  #include<bits/stdc++.h>
using namespace std;
// Prims algo for Minimum Spanning Tree Brute force

class Graph{

    int v;
    vector<vector<pair<int,int>>> adj;
    vector<bool> MstSet;
    vector<int> parent;
    vector<int> key;
public:
    Graph(int n){
        this->v = n;
        adj.resize(v);
        MstSet.resize(v);
        parent.resize(v);
        key.resize(v);

    }

    void AddEdge(int a, int b,int wt, bool undir){
        adj[a].push_back({b,wt});

        if (undir)
        {
            adj[b].push_back({a,wt});
        }
    }

    void Prims(int source){

        for (int i = 0; i < v; i++)
        {
            MstSet[i] = false;
            parent[i] = -1;
            key[i] = (int) 10e5;
        }

        parent[source]= -1;
        key[source] = 0;        

        for (int a = 0; a < v-1; a++)  // v-1 edges in MST
        {   
            int mini = (int) 10e5;
            int u ;
            for (int  i = 0; i < v; i++)
            {
                if (MstSet[i] == false and key[i] < mini)
                {
                    mini = key[i];
                    u = i;
                } 
            }

            MstSet[u] =true;
            
            for(auto it: adj[u]){
                int ve = it.first;
                int weight = it.second;

                if (MstSet[ve]== false and weight < key[ve])
                {
                    key[ve] = weight;
                    parent[ve] = u;
                }
                
            }
        }
        
        for (int i = 0; i < v; i++)
        {
            cout<<parent[i]<<" -- "<<i<<endl;
        }
        return;
    }

};

int main(){
    
    Graph g(5); 
    g.AddEdge(0, 1, 2, 1); // a, b, wt ,undir
    g.AddEdge(0, 3, 6, 1);
    g.AddEdge(1, 2, 3, 1);
    g.AddEdge(1, 3, 8, 1);
    g.AddEdge(1, 4, 5, 1);
    g.AddEdge(2, 4, 7, 0);

    g.Prims(0);


    return 0;
}
