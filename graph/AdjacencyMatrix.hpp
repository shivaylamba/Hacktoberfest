#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include <iostream>
using namespace std;
#include "GraphAdjacencyBase.hpp"
/*typedef struct p{
    int k;
    struct p *Next;
}que;
class Queue{
	que *front,*rear;
	int length;
public:
	Queue()
	{
		front=NULL;
		rear=NULL;
		length=0;
	}
	~Queue()
	{
		front=NULL;
		rear=NULL;
	}
	int Length()
	{
		return length;
	}
	void enque(int Key)
	{

		que *temp;
		temp=new que;
		temp->k=Key;
		temp->Next=NULL;
		if(length==0)
		{
			front=temp;
			rear=temp;
		}
		else
		{
			rear->Next=temp;
			rear=temp;
		}
		
		length++;
	}
	int deque()
	{
		int c;
		c=front->k;
		if(length==1)
		{
			front=NULL;
			rear=NULL;
		}
		else
			front=front->Next;
		length--;
		return c;
	}
	void print()
	{
		que *temp;
		int z=1;
		temp=front;
		while(z)
		{
			cout<<temp->k<<" ";
			temp=temp->Next;
			if(temp==rear)
			{	z=0;
				cout<<temp->k;
			}
			else if(length==1)
			{
				z=0;
			}

		}
	}
};*/
/*
 * 	Class AdjacencyMatrix
 *	Can be used to represent a Graph using adjacency-matrix.
 */
class AdjacencyMatrix : public GraphAdjacencyBase {
	
	int size;
	int **adjacency_matrix;
	public:
		AdjacencyMatrix(int vertices)
		{
			adjacency_matrix = new int*[vertices];
			for(int i = 0; i < vertices; ++i)
			    adjacency_matrix[i] = new int[vertices];
			size=vertices;
			for (int i = 0; i < size; ++i)
	    	{ 
	    		for (int j = 0; j < size; ++j)
	    		{
	    		 	 adjacency_matrix[i][j]=0;
	    		}
	    		 
	    	}

		}
		~AdjacencyMatrix()
		{
			delete adjacency_matrix;
		}
 
	    virtual void print()
	    {
	    	ofstream f;
		    f.open("adj_mat.txt");
	    	for (int i = 0; i < size; ++i)
	    	{ 
	    		for (int j = 0; j < size; ++j)
	    		{
	    		 	f<<adjacency_matrix[i][j]<<" ";
	    		}
	    		f<<endl;
	    	}
	    	f.close();
	    }
		/*
		 * Function: edgeExists
		 * Returns true if an edge exists between vertices i and j, false otherwise.
		 */
	    virtual bool edgeExists(int i, int j)
	    {
        	if(adjacency_matrix[i][j]==1)
        		return true;
        	else
        		return false;
	    }
		/*
		 * Function: vertices
		 * Returns the number of vertices in the adjacency structure.
		 */
	    virtual int vertices()
	    {
	    	return size;
	    }
		/*
		 * Function: edges
		 * Returns the number of edges in the adjacency structure.
		 */
	    virtual int edges()
	    {
	    	int count=0;
	    	for (int i = 0; i < size; ++i)
	    	{
	    		for (int j = 0; j <size; ++j)
	    		{
	    			 if(adjacency_matrix[i][j]==1)
	    			 	count++;
	    		}
	    	}
	    	return count;
	    }
		/*
		 * Function add:
		 * Adds an edge between vertices i and j
		 */
	    virtual void add(int i, int j)
	    {
	    	adjacency_matrix[i][j]=1;
	    }
		/*
		 * Function: remove
		 * Deleted the edge between vertices i and j
		 */
	    virtual void remove(int i, int j)
	    {
	    	adjacency_matrix[i][j]=0;
	    }
		/*
		 * Function: degree
		 * Returns the degree of the vertex i
		 */
	    virtual int degree(int i)
	    {
	    	int count=0;
	    	for (int l = 0; l < size; ++l)
	    	{
	    		if(adjacency_matrix[i][l]==1)
	    			count++;
	    	}
	    	return count;
	    }
	 /*   virtual void dfs_visit(int u,int* visited,void (*work)(int&))
	   {
		visited[u]=1;
		cout<<u<<" ";
		
		for (int i = 0; i < vertices(); ++i)
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
				work(&u);
				dfs_visit(i,visited);
			}
		}
	}
	 
  virtual void bfs(void (*work)(int&))
  {
  	Queue w;
  	int visited[vertices()];
  	for (int i = 0; i < vertices(); ++i)
  	{
  		 visited[i]=0;
  	}
  	for (int j = 0; j< vertices(); ++j)
  	{
  	if(visited[j]==0)
  	{
  		w.enque(j);
	  	while(w.Length()!=0)
	  	{
	  		int u=w.deque();
	  		cout<<u<<" ";
	  		//work(&u);
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
  	}
  	
  }*/
};

#endif /* ifndef ADJACENCY_MATRIX */
