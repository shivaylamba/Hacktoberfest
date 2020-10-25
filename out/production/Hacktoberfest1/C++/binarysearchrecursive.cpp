#include <iostream>
using namespace std;

int binarySearch(int ar[],int low,int high,int item)
{
    int mid=(low+high)/2;
    if(low>high)
    {
        return -1;
    }
    if(item==ar[mid])
    {
        return mid;
    }
    else if(item<ar[mid])
    {
        return binarySearch(ar,low,mid-1,item);
    }
    else{
        return binarySearch(ar,mid+1,high,item);
    }
}
int main()
{
    int ar[10];
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl<<"Enter values of array in sorted order: ";
    for (int i=0; i< n; i++)
    {

        cin>>ar[i];
    }
    cout<<endl<<"Enter item to be searched: ";
    int item;
    cin >> item;
    int res=binarySearch(ar,0,n-1,item);
    if(res==-1)
    {
        cout<<endl<<"Item not found";
    }
    else{
        cout<<endl<<"Item found at: "<<res+1;
    }
}

