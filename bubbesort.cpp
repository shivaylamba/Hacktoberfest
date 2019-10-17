#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& arr)
{    
     int n= arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
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
     }   
    
    return 0;
}
