#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int editDist(string inp , string out){
    int DP[100][100]={};
    int n=inp.length();
    int m=out.length();
    DP[0][0]=0;
    for(int i=1;i<=n;i++) DP[i][0]=DP[i-1][0]+1;
    for(int i=1;i<=m;i++) DP[0][i]=DP[0][i-1]+1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int q1=DP[i-1][j-1];
            int q2=DP[i][j-1];
            int q3=DP[i-1][j];
            DP[i][j]=min(q1,min(q2,q3)) + (inp[i-1]!=out[j-1]);
        }
    }
    return DP[n][m];

}

int main() {
   string a,b;
   cin>>a;
   cin>>b;
   int ans =editDist(a,b);
   cout<<ans;
}

