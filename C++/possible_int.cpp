#include<iostream>
using namespace std;
int ascending(int);
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int asc=0,desc=0;
    asc=ascending(n);
    int b=asc;
    while(b>0)
    {
        int d=b%10;
        desc=desc*10+d;
        b=b/10;
    }
    for(int j=asc;j<=desc;j++)
    {
        int k=ascending(j);
        if(k==asc)
        {
            cout<<j<<" ";
        }
    }
    return 0;
}
int ascending(int x)
{
    int y = x,f=0;
    for (int i = 0; i <= 9; i++)
    {
        y = x;
        while (y > 0)
        {
            int d = y % 10;
            if (d == i)
            {
                f = f* 10 + d;
            }
            y = y / 10;
        }
    }
    return f;
}
