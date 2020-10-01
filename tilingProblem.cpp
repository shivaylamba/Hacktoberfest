/*********************************************
given a brick wall of 4XN and tiles of size 4X1 you have to find out the number
of ways to arrange tiles on the wall

*************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tiling(ll n){
    if(n<0){
        return 0;
    }
    if(n<4){
        return 1;
    }

    return tiling(n-1)+tiling(n-4);
}

int main(){

   // number of row in wall
   ll n;
   cin>>n;

   cout<<tiling(n);

    return 0;
} 
