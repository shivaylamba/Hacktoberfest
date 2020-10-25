#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int *b)
{
     int t=*a;*a=*b;*b=t;
}
void solve(vector<int>& arr)
{    
     int n= arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                 swap(&arr[j],&arr[j-1]);
           // int temp=arr[j-1];
           // arr[j-1]=arr[j];
           // arr[j]=temp;
            }
        }
    }
}
int main(int argc, char const *argv[])
{    vector<int> arr{8,3,11,6,16,20,-10,18,5};
        solve(arr);

   for (int i = 0; i < arr.size(); i++)
     {
         cout<<arr[i]<<" ";
        cout<<endl;
     }   
    
    return 0;
}
