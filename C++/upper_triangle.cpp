#include <iostream>
using namespace std;

int main()
{
    int o;
    cout<<"enter the order of matrix: ";
    cin>>o;

    int ele = (o*(o+1))/2;
    int mat[ele];
    cout<<"enter the elements column wise: ";
    for(int i=0; i<ele; i++)
        cin>>mat[i];

    for(int i=0; i<o; i++)
    {
        for(int j=0; j<o; j++)
        if(i <= j)
        {
            cout<<mat[((j*(j+1))/2) + i]<<ends;
        }   
        else
            cout<<"0"<<ends;
        cout<<endl;
    }
    return 0;
}