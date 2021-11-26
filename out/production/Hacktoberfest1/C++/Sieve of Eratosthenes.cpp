#include <iostream>
#include <cstring>
using namespace std;

int main()
 {
   long long int t,n;
   cin>>t;

   for(int i=1;i<=t;i++)
   {
     cin>>n;

     bool ans[n+1];
     memset(ans,true,sizeof(ans));

     for(int j=2;j*j<=n;j++)
     {
         if(ans[j]==true)
         {
             for(int k=j*j;k<=n;k+=j)
             {
                 ans[k]=false;
             }
         }
     }

     for(int j=2;j<=n;j++)
     {
         if(ans[j])
         cout<<j<<" ";
     }
     cout<<endl;
   }
 }
