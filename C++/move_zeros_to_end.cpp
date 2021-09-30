#include<iostream>
#include<vector>
using namespace std;
int move_zero(vector<int> &arr, int n)
{
    int temp;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            for(int j=n-1; j>i; j--)
            {
                if(arr[j] != 0)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
    return n;
}

int main()
{
    vector<int> arr;
    int size=0, input;
    cout<<"Enter size of array";
    cin>>size;
    cout<<"Enter array element: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>input;
        arr.push_back(input);
    }
    int k = move_zero(arr, size);
    cout<<"Updated array is: "<<endl;
    for(int i=0; i<k; i++)
    {
        cout<<arr[i];
    }
}