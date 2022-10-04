//Code Chef :  Problem Code: JDELAY      problem name:Judging Delay

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int t,s,j,n,c;
    cin>>t;
    for(int i=0;i<t;i++)
        {
            c=0;
            cin>>n;
            for(int k=0;k<n;k++)
            {
                cin>>s>>j;
                if(j-s>5)
                    {
                        c++;
                    }
            }
            cout<<c<<endl;
        }
        return 0;
}
