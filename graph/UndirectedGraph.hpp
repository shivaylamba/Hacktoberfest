#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"

/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
class UndirectedGraph : public AbstractGraph {

	GraphAdjacencyBase *base;
  AdjacencyMatrix *M;
  AdjacencyList *L;
		
 	public:

  	/*
   	* Constructor: UndirectedGraph
   	*
   	* Parameters: mode
   	* Used to decide which representation to use
   	* 'm' for AdjacencyMatrix
   	* 'l' for AdjacencyList
   	*/
  	UndirectedGraph(int Vertices, char rep)
    {
      if(rep=='m')
      {
        M=new AdjacencyMatrix(Vertices);
        base=M;
      }
      else if(rep=='l')
      { 
        L=new AdjacencyList(Vertices);
        base=L;
      }
    }
  /*
   * Destructor
   */
  ~UndirectedGraph()
  {
       base=NULL;
  }
  	/*
  	* Destructor
  	*/
  
    virtual bool edgeExists(int i, int j)
    {
      return base->edgeExists(i,j);
    }
      /*
       * Function: edges
       * Returns the number of edges in the adjacency structure.
       */
    virtual int edges()
    {
      int c=base->edges();
      return c/2;
    }
      /*
       * Function: vertices
       * Returns the number of vertices in the adjacency structure.
       */
    virtual int vertices()
    {
        return base->vertices();
    }
    virtual void print()
  {
    return base->print();
  }
      /*
       * Function add:
       * Adds an edge between vertices i and j
       */
    virtual void add(int i, int j)
    {
       base->add(i,j);
       base->add(j,i);
    }
      /*
       * Function: remove
       * Deleted the edge between vertices i and j
       */
    virtual void remove(int i, int j)
    {
      base->remove(i,j);
      base->remove(j,i);
    }
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
      /*
       * Function dfs:
       * Does a depth first traversal of the entire graph.
       * Runs the given function work, with the value of each vertex.
       */
   /* virtual void dfs(void (*work)(int&)) = 0;
      /*
       * Function bfs:
       * Does a breadth first traversal of the entire graph.
       * Runs the given function work, with the value of each vertex.
       */
   // virtual void bfs(void (*work)(int&)) = 0;
  	
	};
	
#endif /* ifndef UNDIRECTED_GRAPH */
