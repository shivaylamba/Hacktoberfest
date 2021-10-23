#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int source;
        int destination;
        int weight;
};


Edge input[50];

bool sortByWeight(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v,int* parent){
    if(parent[v] == v) 
        return v;
    return findParent(parent[v],parent);
}

void kruskals(int E,int n){
    // sort input array in asc order based on weights;
    sort(input,input+E,sortByWeight);

    Edge *output = new Edge[n-1];
    int *parent = new int[n];
    // parent array containin parent of every edge
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    while(count != n-1){
        Edge currentEdge = input[i];

        // check if current edge can be added or not 

        int sourceParent = findParent(currentEdge.source,parent);
        int destParent = findParent(currentEdge.destination,parent);

        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++; 
            parent[sourceParent] = destParent;
        }
        i++;

    }
    for(int i=0;i<n-1;i++){
        if(output[i].source< output[i].destination)
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<"\n";
        else
           cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<"\n"; 
    }
}

int main(){
    int n,E;
    cin>>n>>E;

    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    kruskals(E,n);
}
