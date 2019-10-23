#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include <iostream>
using namespace std;
#include "GraphAdjacencyBase.hpp"

/*
 * 	Class AdjacencyList
 *	Can be used to represent a Graph using adjacency-list.
 */
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
}; */
typedef struct s
{
	int key;
	struct s* next;
}Node;

class AdjacencyList : public GraphAdjacencyBase {

	int size;
	Node **adjacency_list;


	public:
	AdjacencyList(int vertices)
	{	
		size=vertices;
		adjacency_list=new Node*[vertices];
		for (int i = 0; i < vertices; ++i)
		{
			adjacency_list[i]=NULL;
		}
		 
	}
	~AdjacencyList()
	{
		delete adjacency_list;
	}

    virtual Node* createNode()
	{
        Node *temp;
        temp = new Node;
        temp->next=NULL;
        temp->key=0;
        return temp;
	}
	virtual void print()
	{
		ofstream f;
		f.open("adj_lst.txt");
		for (int i = 0; i < size; ++i)
  		{
  			Node *temp,*NEXT;
  			temp=adjacency_list[i];
  			while(temp!=NULL)
	  		{
	  			f<<temp->key<<" ";
	  			temp=temp->next;
	  			 
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
     	Node *temp,*NEXT;
     	int count=0;
     	temp=adjacency_list[i];
  		while(temp!=NULL)
	  	{
	  		if(temp->key==j)
	  			return true;
	  		temp=temp->next;
	  	}
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
  		Node *temp,*NEXT;
  		for (int i = 0; i < size; ++i)
  		{
  			temp=adjacency_list[i];
  			while(temp!=NULL)
	  		{
	  			temp=temp->next;
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
  	 	Node *temp,*NEXT,*t; 
  	    temp=adjacency_list[i];
  	    t=createNode();
  		t->key=j;
  		t->next=NULL;
  	    if(temp!=NULL)
  	    {
  	     
  		while(temp->next!=NULL)
  		{
  			temp=temp->next;
  			//NEXT=temp->next;
  		}
  		temp->next=t;
  		//cout<<temp->next->key;
     	}
     	else
     	{
     		adjacency_list[i]=t;
     		//cout<<adjacency_list[i]->key;
     	}
  	}
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  	virtual void remove(int i, int j)
  	{
  		Node *temp,*NEXT,*PREV; 
  		int d=0;
  	    temp=adjacency_list[i];
  		while(temp->key!=j)
  		{
  			PREV=temp;
  			temp=temp->next;
  			d=1;
  		} 
  		if(d==0)
  		{
  			adjacency_list[i]=temp->next;
  		}
  		else
        	PREV->next=NULL;
        delete temp;
  	}
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  	virtual int degree(int i)
  	{
  		int count=0;
  		Node *temp,*NEXT;
  		temp= adjacency_list[i];
  		 
         
  			while(temp!=NULL)
	  		{
	  			temp=temp->next;
	  			count++;
	  		}
		return count;
  	}
  	   /* virtual void dfs_visit(int u,int* visited)
	   {
		visited[u]=1;
		cout<<u<<" ";
		
		for (int i = 0; i < vertices(); ++i)
		{
			if(edgeExists(u,i)==1 && visited[i]==0)
				dfs_visit(i,visited);
		}
	}
	virtual void dfs() 
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
				//work(&u);
				dfs_visit(i,visited);
			}
		}
	}
	 
  virtual void bfs()
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
  	
  } */


		  	
};  	
#endif /* ifndef ADJACENCY_LIST */
