#include <iostream>
using namespace std;

int main()
{
    int o;
    cout<<"enter the order of matrix: ";
    cin>>o;

    int ele = (3*o)-2;
    int mat[ele];
    cout<<"enter the elements row wise: ";
    for(int i=0; i<ele; i++)
        cin>>mat[i];

    for(int i=0; i<o; i++)
    {
        for(int j=0; j<o; j++)
            if(i-j == 1 || i-j == -1 || i==j)
                cout<<mat[(2*j)+i]<<ends;
            else
                cout<<"0"<<ends;
            cout<<endl;
    }
}