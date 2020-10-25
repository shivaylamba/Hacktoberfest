#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

char arr[1001][1001];
bool vis[1001][1001] = {false};
int n, m;

bool isValid(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    if(vis[x][y] == true || arr[x][y] == '#'){
        return false;
    }

    return true;
}

void dfs(int x, int y){
    vis[x][y] = true;
    if(isValid(x-1, y)){
        dfs(x-1, y);
    }
    if(isValid(x+1, y)){
        dfs(x+1, y);
    }
    if(isValid(x, y-1)){
        dfs(x, y-1);
    }
    if(isValid(x, y+1)){
        dfs(x, y+1);
    }
}

int main()
{
    //OJ;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '.' && vis[i][j] == false){
                dfs(i,j);
                count++;
            }
        }
    }

    cout << count << endl;
}
