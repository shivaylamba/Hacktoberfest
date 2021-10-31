#include <iostream>
using namespace std;
int main() {
   int n,i,j,temp;
   cout<<"Enter n"<<endl;
   cin>>n;
   int arr[n];
   cout<<"Enter data"<<endl;
   for(i=0;i<n;i++){
       cin>>arr[i];
   }
   for(i=0;i<n-1;i++){
       for(j=0;j<n-1-i;j++){
          if(arr[j]>arr[j+1]){
              temp=arr[j+1];
              arr[j+1]=arr[j];
              arr[j]=temp;
          }
       }
   }
   for(i=0;i<n;i++){
       cout<<arr[i]<<' ';
   }

    return 0;
}
