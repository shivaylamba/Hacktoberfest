#include <iostream>
#include<map>
#include<list>
#include<queue>
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
        map<T,bool> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node=q.front();
            q.pop();
            cout<<node<<" ";
            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    //mark that neighbour as visited
                    visited[nbr]=true;
                }
            }
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
