#include<bits/stdc++.h>
using namespace std;
int main()
{

       int n;
       cin>>n;
       int a[n];
       for (int i = 0; i < n; i++)
       {
        cin>>a[i];
       }

             int key;
             cin>>key;

             int index = -1;

             for (int i = 0; i < n; i++)
             {
                if(key==a[i]) index = i;

             }
             
        
         cout << index << endl;
    return 0;
}
