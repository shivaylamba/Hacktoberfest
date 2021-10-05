#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int a=0, b=0, c=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='A')a++;
            else if(s[i]=='B')b++;
            else c++;
        }
        if((a+b+c)%2!=0)cout<<"NO"<<endl;
        else{
            if(b-a == c)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
