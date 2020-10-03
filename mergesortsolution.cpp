#include <iostream>
using namespace std;
int partitions(int *a,int s,int e){
    int pivot=e,low=s,high=e;
    while(low<high){
        if(a[low]<a[pivot]){
            low++;
        }
        else if(a[high]>a[pivot]){
            high--;
        }
        else
            swap(a[low],a[high]);
    }

    swap(a[pivot],a[low]);
    return low;
}
void quicksort(int *a,int s,int e){
    if(s<e){
    int pindex=partitions(a,s,e);
    quicksort(a,s,pindex-1);
    quicksort(a,pindex+1,e);
    }
}
int main()
{
    int n,a[20];
   cout<<"Enter length of an array"<<endl;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }

   quicksort(a,0,n-1);
   for(int i=0;i<n;i++){
    cout<<a[i]<<' ';
   }

    return 0;
}
