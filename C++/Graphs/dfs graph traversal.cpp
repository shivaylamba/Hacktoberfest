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
    void dfs_helper(T src,map<T,bool> &visited){
        //recursive function that will traverse the graph
        cout<<src<<" ";
        visited[src]=true;
        //go to all neighbour of that node that is not visited
        for(T nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);

            }
        }


    }
    void dfs(T src){
        map<T,bool> visited;
        //mark all the nodes as not visited in begining
        for(auto p:l){
            T node=p.first;
            visited[node]=false;
        }
        //call the helper function
        dfs_helper(src,visited);

    }

};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);
}
