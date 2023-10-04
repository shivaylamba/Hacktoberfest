#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int ar[n];

    for(int i = 0; i<n; i++)
    {cin>>ar[i];}

    int key;
    cin>>key;

    int mid = 0;
    int h = n-1;
    int l = 0;

    while(1)
    {
        mid = int((h+l)/2);
        if (ar[mid] == key)
        {
            cout<<"Found at :"<<mid<<endl; break;
        }

        else if (h == l)
        {
            cout<<"NOT Found."<<endl;
        }

        else if (ar[mid] > key)
        {
            h = mid-1;
        }

        else if (ar[mid] < key)
        {
            l = mid+1;
        }
        
        
    }
}