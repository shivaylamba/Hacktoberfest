#ifndef ABSTRACT_GRAPH
#define ABSTRACT_GRAPH 1
#include <iostream>
using namespace std;
/*
 * An interface to represent any type of Graph
 */
 typedef struct p{
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
	void Print()
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
};
class AbstractGraph {
 public:
  /* Destructor:
   * releases all resources acquired by the class
   */
  virtual ~AbstractGraph(){};
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  virtual bool edgeExists(int i, int j) = 0;
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  virtual int edges() = 0;
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */

  virtual void print()=0;

  virtual int vertices() = 0;
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
  virtual void add(int i, int j) = 0;
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  virtual void remove(int i, int j) = 0;
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
    

    
  	//}
  	
  //}
};

#endif /* ifndef ABSTRACT_GRAPH */
