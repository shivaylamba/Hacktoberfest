#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int pro=0;
    int sd=0;
    int bd=0;
    for(int i=1;i<n;i++)
    {
        if(p[i]>=p[i-1])
        {
            sd++;
        }
        else
        {
            pro+=p[sd]-p[bd];
            bd=sd=i;
        }
    }
    pro+=p[sd]-p[bd];
    cout<<pro;
}
/*
Sample Input
9
11
6
7
19
4
1
6
18
4
Sample Output
30
*/
