#include<iostream>
using namespace std;
int main ()
{
   int i, j,temp;
   int n;

   cout<<"Enter the no. of Elements in the Array: ";
   cin>>n;
   int arr[n];

   cout<<"Enter "<<n<<" Elements :";
   for(int i=0; i<n; i++){
    cin>>arr[i];
   }

   cout<<"List before Sorting: "<<endl;
   for(i = 0; i<n; i++) 
   {
      cout <<arr[i]<<"\t";
   }
   
   cout<<endl;
   
   for(i = 0; i<n; i++) 
   {
    for(j = i+1; j<n; j++)
   {
      if(arr[j] < arr[i])
      {
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   
   }
   cout <<"List after Sorting: \n";
   for(i = 0; i<n; i++) 
   {
    cout <<arr[i]<<"\t";
    }
    
    return 0;
}