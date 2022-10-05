#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter a number to check whether it is prime or not  : "<<endl;
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"1 is neither prime nor composite "<<endl;
        
    }
    else{
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        c++;
        
    }
    if(c==2)
    cout<<"The given number is prime "<<endl;
    else
    cout<<"The given number is not prime "<<endl;
    }
    
}
