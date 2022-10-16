#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
class Graph{
    list<int> *l;
    int V;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }
    void addedge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);

    }
    bool is_tree(){
        bool *visited=new bool[V];
        int *parent=new int[V];

        queue<int> q;

        //no node is visited initially
        for(int i=0;i<V;i++){
            visited[i]=false;
            parent[i]=i;

        }
        int src=0;
        q.push(src);
        visited[src]=true;
        //pop out one  node and visit its nbr
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nbr:l[node]){
                if(visited[nbr]==true and parent[node]!=nbr){

                    return false;
                }
                else if(!visited[nbr]){
                    visited[nbr]=true;
                    parent[nbr]=node;
                    q.push(nbr);

                }
                
            }
        }
        return true;




    }

};
int main(){
    Graph g(4);
    g.addedge(0,1);
    g.addedge(3,2);
    g.addedge(1,2);
    g.addedge(0,3);
    g.is_tree();
    if(g.is_tree()){
        cout<<"Yes it is a tree"<<endl;
    }
    else{
        cout<<"not a tree"<<endl;
    }
}