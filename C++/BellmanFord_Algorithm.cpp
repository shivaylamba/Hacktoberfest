#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> BellmanFord_Algo(int V, int src, vector<vector<int>> edges){

    //create the vector
    vector<int> dist(V+1,INT_MAX);
    dist[src] = 0;

    //relax the edges V-1 times
    for(int i=0; i<V-1;i++){
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u]!=INT_MAX and dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    //for negative wt cycle
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u]!=INT_MAX and dist[u] + wt < dist[v]){
            cout<<"Negative wt cycle exist"<<endl;
            exit(0);
        }
    }
    return dist;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> edgeList;

    while(m--){
        int x,y,w;
        cin>>x>>y>>w;
        edgeList.push_back({x,y,w});
    }
    int src = 1;
    vector<int> distances = BellmanFord_Algo(n,src,edgeList);

    for(int i=src; i<=n; i++){
        cout<<"Node "<<i<<" is at distance "<<distances[i]<<endl;
    }

    /*
3 3
1 2 3
2 3 4
1 3 -10
    */

    return 0;
}