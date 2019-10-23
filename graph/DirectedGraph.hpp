#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"

/*
* A class to represent a directed graph.
*/
class DirectedGraph : public AbstractGraph {
	
	GraphAdjacencyBase *base;
	AdjacencyMatrix *M;
	AdjacencyList *L;
	int z;
	public:
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, char rep)
	{	

        if(rep=='m')
        {
        	M=new AdjacencyMatrix(numVertices);
			base=M;
        }
		else if(rep=='l')
		{ 
			L=new AdjacencyList(numVertices);
			base=L;
		}
	}
	/*
	 * Destructor
	 */
	~DirectedGraph()
	{
       base=NULL;
	}
		/*
	   * Function: edgeExists
	   * Returns true if an edge exists between vertices i and j, false otherwise.
	   */
	virtual bool edgeExists(int i, int j)
	{
		return base->edgeExists(i,j);
	}
	  /*
	   * Function: edges
	   * Returns the number of edges in the adjacency structure.
	   */
	virtual void print()
	{
		return base->print();
	}
	virtual int edges()
	{
	  	return base->edges();
	}
	  /*
	   * Function: vertices
	   * Returns the number of vertices in the adjacency structure.
	   */
	virtual int vertices()
	{
	  	return base->vertices();
	}
	  /*
	   * Function add:
	   * Adds an edge between vertices i and j
	   */
	virtual void add(int i, int j)
	{
 	    base->add(i,j);
	}
	  /*
	   * Function: remove
	   * Deleted the edge between vertices i and j
	   */
	virtual void remove(int i, int j)
	{
		base->remove(i,j);
	}
	  /*
	   * Function dfs:
	   * Does a depth first traversal of the entire graph.
	   * Runs the given function work, with the value of each vertex.
	   */
	virtual void dfs_visit(int u,int* visited)
	{
		visited[u]=1;
		cout<<u<<" ";
		for (int i = 0; i <vertices(); ++i)
		{
			if(edgeExists(u,i)==1 && visited[i]==0)
				dfs_visit(i,visited);
		}
	}
	virtual void dfs(void (*work)(int&)) 
		{
	    int visited[vertices()];
		for (int i = 0; i < vertices(); ++i)
		{
			 visited[i]=0;
		}
		for (int i = 0; i < vertices(); ++i)
		{
			if(visited[i]==0)
			{
				work(i);
				dfs_visit(i,visited);
				cout<<endl;
			}
		}
	}
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */

    virtual void bfs(void (*work)(int&))
    {

  	Queue w;
  	int z;
  	int visited[vertices()];
  	for (int i = 0; i < vertices(); ++i)
  	{
  		 visited[i]=0;
  	}
  	//for (int j = 0; j< vertices(); ++j)
  	//{
  	//if(visited[j]==0)
  	//{
  		w.enque(0);
	  	while(w.Length()!=0)
	  	{
	  		int u=w.deque();
	  		//cout<<u<<" ";
	  		work(u);
	  		visited[u]=1;
	  		for (int i = 0; i < vertices(); ++i)
	  		{
	  			if(edgeExists(u,i)==1 && visited[i]==0)
	  			{
	  			 	w.enque(i);
	  			}
	  		}
	  	}
	}
	/*virtual void dfs_visit(int u)
	{
		visited[u]=1;
		cout<<u<<" ";
		for (int i = 0; i <vertices(); ++i)
		{
			if(edgeExists(u,i)==1 && visited[i]==0)
				dfs_visit(i);
		}
	}
	virtual void dfs(void (*work)(int&)) = 0;
	{
	    int visited[vertices()];
		for (int i = 0; i < vertices(); ++i)
		{
			 visited[i]=0;
		}
		for (int i = 0; i < vertices(); ++i)
		{
			if(visited[i]==0)
			{
				dfs_visit(i);
			}
		}
	}
	  /*
	   * Function bfs:
	   * Does a breadth first traversal of the entire graph.
	   * Runs the given function work, with the value of each vertex.
	   */
	//virtual void bfs(void (*work)(int&)) = 0;*/
		
};

#endif /* ifndef DIRECTED_GRAPH */
