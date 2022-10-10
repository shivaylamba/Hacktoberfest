#include <bits/stdc++.h>
using namespace std;
vector<int> depth;
vector<vector<int>> mat;
vector<vector<int>> adj;
void dfs(int nd, vector<int> &vis)
{
    vis[nd] = true;
    for (auto it : adj[nd])
    {
        if (!vis[it])
        {
            depth[it] = depth[nd] + 1;
            mat[it][0] = nd;
            dfs(it, vis);
        }
    }
}
int calculateLCA(int x, int y, int n)
{
    int dpx = depth[x];
    int dpy = depth[y];
    int dif = abs(dpx - dpy);
    if (dpx < dpy)
    {
        swap(x, y);
        swap(dpx, dpy);
    }
    int t = 0, val = 0;
    while (dif > 0)
    {
        while (val <= dif)
        {
            t++;
            val = 1 << t;
        }

        t--;
        x = mat[x][t];
        dpx = depth[x];
        dif -= (1 << t);
        t = 0;
    }
    int lca;
    if (x == y)
    {
        lca = y;
    }
    else
    {
        for (int ht = log2(n); ht >= 0; ht--)
        {
            if (mat[x][ht] != mat[y][ht])
            {
                x = mat[x][ht];
                y = mat[y][ht];
            }
        }
        lca = mat[x][0];
    }
    return lca;
}
int main()
{
    int n;
    cin >> n;
    int m = n - 1;
    adj = vector<vector<int>>(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    depth = vector<int>(n);
    int t = log2(n);
    mat = vector<vector<int>>(n, vector<int>(t + 1, -1));
    vector<int> vis(n);
    dfs(0, vis);
    for (int j = 1; j <= t; j++)

    {
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j - 1] == -1)
                mat[i][j] == -1;
            else
                mat[i][j] = mat[mat[i][j - 1]][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int r, x, y;
        cin >> r >> x >> y;
        r--;
        x--;
        y--;

        int LCAorg = calculateLCA(x, y, n);
        int LCAcheck = calculateLCA(r, LCAorg, n);
        if (LCAcheck != LCAorg)
        {
            cout << LCAorg + 1 << "\n";
        }
        else
        {
            int LCAxr = calculateLCA(r, x, n);
            int LCAyr = calculateLCA(r, y, n);
            if (LCAxr == LCAorg)
            {
                cout << LCAyr + 1 << "\n";
            }
            else
                cout << LCAxr + 1 << "\n";
        }
    }
}