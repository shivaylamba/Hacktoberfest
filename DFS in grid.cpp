#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3 + 7;
bool vis[mxN][mxN];
char a[mxN][mxN];
int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

void DFSinGrid(int i,int j){
    vis[i][j]=1;
    for(int l=0;l<4;l++){
        int nr=i + dxy[l][0];
        int nc=j + dxy[l][1];
        
        if(!vis[nr][nc] && a[nr][nc]=='.'){
            DFSinGrid(nr,nc);
            
        }
    }
}


int main()
{
    int n,m,c=0;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(!vis[i][j] && a[i][j]=='.'){
                DFSinGrid(i,j);
                c++;
            }
            
        }
    }
    
    cout<<c<<"\n";

    return 0;
}
