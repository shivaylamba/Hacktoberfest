#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y);

class Minheap{   // class defining the Heap Structure

  int *harr;
  int heap_size;
  int capacity;

public:
  Minheap(int capacity);

  void Heapify(int );

  int parent(int x){ return (x-1)/2;}

  int left(int x){ return (2*x + 1);}
  int right(int x){ return (2*x + 2);}

  int extractMin();

  void decreasekey(int i,int value);

  int getmin(){

   return harr[0];}

  void deleteKey(int x);

  void insertkey(int x);
};

Minheap::Minheap(int cap)
{
  heap_size=0;
  capacity= cap;
  harr = new int[cap];
}

void Minheap::insertkey(int x) //inserting a value to heap
{
  if(heap_size==capacity)
  { cout<<"Not Possile to create Heap";
  return;}

  heap_size++;
  int i=heap_size-1;
  harr[i]=x;

  while(i!=0 && harr[parent(i)]>harr[i])
  {
    swap(&harr[parent(i)],&harr[i]);
    i=parent(i);
  }
}

void Minheap::decreasekey(int i,int value) // decreasing the value of a given key to a specified value
{
  harr[i]=value;
  while(i!=0 && harr[parent(i)]>harr[i])
  {
    swap(&harr[parent(i)],&harr[i]);
    i=parent(i);
  }
}

int Minheap::extractMin() //To extract the min value
{
  if(heap_size<=0)
   return INT_MAX;
  if(heap_size==1)
  {
    heap_size--;
    return harr[0];
  }

  int root=harr[0];
  harr[0]=harr[heap_size-1];
  heap_size--;
  Heapify(0);

  return root;
}

void Minheap::deleteKey(int x) // deleting a given key
{
  decreasekey(x,INT_MIN);
  extractMin();
}

void Minheap::Heapify(int x) // Function to maintain Min Heap property
{
  int l=left(x);
  int r=right(x);
  int smallest=x;

  if(l<heap_size && harr[l]<harr[x])
   {smallest=l;}
  if(r<heap_size && harr[r]<harr[smallest])
   {smallest=r;}
  if(x!=smallest)
  {
    swap(&harr[smallest],&harr[x]);
    Heapify(smallest);
  }
}

void swap(int *x,int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}

int main(void)
{
  Minheap obj(11);
  obj.insertkey(3);
  obj.insertkey(2);
  obj.deleteKey(1);
  obj.insertkey(15);
  obj.insertkey(4);
  obj.insertkey(5);
  obj.insertkey(45);
  cout<<obj.getmin();

}
