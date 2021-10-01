// It is used to find single source shortest path in Directed graph have negative edge but no negative cycle. Applicable for undirected graph as well but for positive edges as negative edge in undirected lead to cycle to itself.

#include <bits/stdc++.h>
using namespace std;

class graph{
    vector<vector<int>> edgelist;
    public:
    void addedge(int x,int y,int w)
    {
        vector<int> edge;
        edge.push_back(x);
        edge.push_back(y);
        edge.push_back(w);
        edgelist.push_back(edge);
    }
    void bellman(int src)
    {
        int n = 5;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<n-1;i++)
        {
            for(auto edge:edgelist)
            {
                if(dist[edge[0]]+edge[2] < dist[edge[1]])
                {
                    dist[edge[1]] = dist[edge[0]]+edge[2];
                }
            }
        }
        for(int i=0;i<dist.size();i++)
        {
            cout<<"Dist of "<<src<<" to "<<i<<" is "<<dist[i]<<"\n";
        }
    }
};

int main()
{
    graph g;
    g.addedge(0, 1, -1);
    g.addedge(0, 2, 4);
    g.addedge(1, 2, 3);
    g.addedge(1, 3, 2 );
    g.addedge(1, 4, 2 );
    g.addedge( 3, 2, 5 );
    g.addedge( 3, 1, 1);
    g.addedge( 4, 3, -3 );
    g.bellman(0);
}
