#include <iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T> > l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src){
        map<T,int> dist;
        queue<T> q;
       
        //all other source will have distance infinity
        for(auto node_pair:l){
            T node=node_pair.first;
            dist[node]=INT_MAX;
        }

        q.push(src);
        dist[src]=0;
        

        while(!q.empty()){
            T node=q.front();
            q.pop();
            // cout<<node<<" ";
            for(auto nbr:l[node]){
                if(dist[nbr]==INT_MAX){
                    q.push(nbr);
                    //mark that neighbour as visited
                    dist[nbr]=dist[node]+1;
                }
            }
        }
        //print the distance for every node
        for(auto node_pair:l){
            T node=node_pair.first;
            int d=dist[node];
            cout<<"Node "<<node<<" Dist from source : "<<d<<endl;
        }
    }

};
int main() {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
   
    

    g.bfs(0);

    return 0;
   
}
