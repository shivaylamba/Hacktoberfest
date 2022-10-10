#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
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
int color[100001];
int n, m;

bool dfs(int u, int c, int par)
{
    visited[u] = true;
    color[u] = c;
    for (auto a : adj[u])
    {
        if (visited[a] == false)
        {
            if (color[a] == 0)
            {
                if (!dfs(a, color[u] ^ 3, u))
                {
                    return false;
                }
            }
            if (color[a] == color[u])
            {
                return false;
            }
        }
    }

    return true;
}

bool color_all()
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            if (!dfs(i, 1, -1))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    OJ;
    FIO;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (color_all())
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
