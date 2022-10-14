#include <iostream>
#include <vector>
using namespace std;

void conquer(vector<int> &vec,int s,int e,int mid)
{
    int len=e-s+1;
    vector<int> merged(len);
    int i=s;
    int j=mid+1;
    int index=0;
    while(i<=mid && j<=e)
    {
        if(vec[i]<=vec[j])
        {
            merged[index++]=vec[i++];
        }
        else
        {
            merged[index++]=vec[j++];
        }
    }
    while(i<=mid)
    {
        merged[index++]=vec[i++];
    }
    while(j<=e)
    {
        merged[index++]=vec[j++];
    }

    for(int i=0,j=s;i<len;i++,j++)
    {
        vec[j]=merged[i];
    }
    merged.clear();
}
void divide(vector<int> &vec,int s,int e)
{
    if(s<e)
    {
        int mid=s+(e-s)/2;
        divide(vec,s,mid);
        divide(vec,mid+1,e);
        conquer(vec,s,e,mid);
    }
}

void printArr(vector<int> vec)
{
    for(int n : vec)
    {
        cout<<n<<" ";
    }
}

int main()
{
    int n; // size of an array/vector
    cout<<"\nEnter Size of an Array : ";
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter element "<<i+1<<" : ";
        int element;
        cin>>element;
        vec.push_back(element);
    }
    cout<<"\nBefore Sorting\n";
    printArr(vec);
    divide(vec,0,n-1);
    cout<<"\nAfter Sorting\n";
    printArr(vec);
    vec.clear();
    return 0;
}
