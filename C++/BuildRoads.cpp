#include <iostream>
#include <vector>
#include<list>
using namespace std;

#define ll long long int

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool visited[100001] = {false};
list<int> adj[100001];

void dfs(int index, list<int> *adj){
    visited[index] = true;
    for(auto a: adj[index]){
        if(visited[a] == false){
            dfs(a, adj);
        }
    }
}


int main()
{
    OJ;
    FIO;
    int n, r;
    cin >> n >> r;
    int a, b;
    for(int i=0; i<r; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<long long int> ans;
    for(int i=1; i<=n; i++){
        if(visited[i] == false){
            ans.push_back(i);
            dfs(i, adj);
        }
    }

    cout << ans.size()-1 << endl;
    for(int i=1; i<ans.size(); i++){
        cout << ans[i] << " " << ans[i]-1 << endl;
    }
}
