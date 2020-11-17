#include<bits/stdc++.h>
using namespace std;

/* Simple Algorithm:-
Let the two given numbers be 'a' and 'b'
1) Initialize result 'res' as 0.
2) Do following while 'b' is greater than 0
   a) If 'b' is odd, add 'a' to 'res'
   b) Double 'a' and halve 'b'
3) Return 'res'.
*/

int russianPeasant(int a,int b)
{
    if(a==0 || b==0)
    return 0;
    int res=0;
    while(b>0)
    {
        if(b&1)
        res+=a;
        a=a<<1;
        b=b>>1;
    }
    return res;
}

int main()
{
    cout<<russianPeasant(18,0)<<endl;
    cout<<russianPeasant(100,31)<<endl;
    return 0;
}