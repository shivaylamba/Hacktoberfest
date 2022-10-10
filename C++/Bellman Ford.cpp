// Bellman Ford's Algorithm for finding the shortest path in weighted graphs

#include <iostream>
#include <climits>

using namespace std;

class Edge{
public:
	int src,dest,weight;

	Edge(int src,int dest,int weight){
		this->weight = weight;
		this->src = src;
		this->dest = dest;
	}

	Edge(){}
};

class Graph{
	int v,e;
	Edge* arr;

public:
	Graph(int v,int e){
		this->v = v;
		this->e = e;
		arr = new Edge[e];
	}

	void addEdge(int src,int dest,int weight,int node){
		arr[node].src = src;
		arr[node].dest = dest;
		arr[node].weight = weight;
	}

	void bellmenFord(int src){

		int distance[v];

		for(int i=0;i<v;i++){
			if(v==src){
				distance[v] = 0;
			}else{
				distance[v] = INT_MAX;
			}
		}

		for(int i=1;i<=v-1;i++){
			for(int j = 0;j < e;j++){

				int s = arr[j].src;
				int d = arr[j].dest;
				int wt = arr[j].weight;

				if(distance[s]!=INT_MAX and distance[s] + wt < distance[d]){
					distance[d] = distance[s] + wt;
					cout<<"Update Check ";
					cout<<s<<" "<<d<<" "<<wt<<" -> Result is ";
					cout<<distance[d]<<endl;
				}
				
			}
		}

		for(int i=0;i<v;i++){
			cout<<"Node "<<i<<" is at a distance of "<<distance[i]<<endl;
		}
	}
};

int main(){

	int v,e;

	cin>>v>>e;

	Graph g(v,e);

	for(int i=0;i<e;i++){

		int src,dest,weight;

		cin>>src>>dest>>weight;

		g.addEdge(src,dest,weight,i);
	}

	g.bellmenFord(0);

	return 0;
}

