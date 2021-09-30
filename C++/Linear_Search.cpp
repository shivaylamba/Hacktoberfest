//Linear Search code sample in C++
/*By Pratyaksh Khurana*/
#include<bits/stdc++.h>
using namespace std;

int func(int array[],int n,int key)
{
  // array size is 0
  if(n == 0)         
    return -1;
  
   //comparing the key 
  for (int i = 0; i < n; i++)
  {
    if(array[i] == key)
      return i;       // returns the index of the element if found 
  }
  //element not found
  return -1;
}
int main()
{
  int n,key,idx = -1;
  cin>>n>>key; // taking input from the user, size of the array and the target element
  int array[n];
  
  // input elements in the array
  for (int i = 0; i < n; i++)
    cin>>array[i];
 
  idx = func(array,n,key);  // this function returns the index of the element 
                               
  if(idx == -1) // if not found returns -1
   cout<<"Not found";
  else 
   cout<<"Found at index "<<idx;  
   
  return 0;
}
