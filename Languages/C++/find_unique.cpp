#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;

int main()
{
    //THIS Program finds one unique element amongst other 
    //repeating elements. Repeating elements must repeat even times.
    //It uses XOR to find the answer
    //example - 2 3 4 4 2 4 4
    //answer - 3
    int n;
    cout<<"Enter number of elements. ";
    cin>>n;
    unsigned int temp;
    unsigned int ans1=0;
    cout<<"Enter the elements. "<<endl;
    for(int i=0; i<n; ++i)
    {
        cin>>temp; 
        ans1 = ans1^temp;
    }
    cout<<"Unique element is "<<ans1<<endl;
    return 0;
}
