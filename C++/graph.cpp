#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class pair
{
};
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storedDfs)
{
    storedDfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[node])
        {
            dfs(node, vis, adj, storedDfs);
        }
    }
}
vector<int> dfsofGraph(int n, vector<int> adj)
{
    vector<int> vis(n + 1, 0);
    vector<int> storedDfs;
    for (int i = 1; i = < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, storedDfs);
        }
    }
    return storedDfs
}

// .............................//................//.....................................

vector<int> bfsofGraph(int n, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis[n + 1, 0];

    for (int i = 0; i < v; i++)
    {
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    return bfs;
}

// .............................//................//.....................................

bool detectCycle(int s, int n, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    vis[s] true;
    q({s, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push({it, node});
            }
            else if (par != it)
                return true;
        }
    }
    return false;
}
bool CheckCycleBFS(int n, vector<int> adj)
{
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, n, vis, adj))
                return true;
        }
    }
}

// .............................//................//.....................................

bool detectCycleDFS(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[s] = 1;
    for (auto it : adj[s])
    {
        if (!vis[it])
        {
            if (detectCycleDFS(it, node, vis, adj))
                return true;
        }
        else if (parent != it)
            return true;
    }
    return false;
}
bool CheckCycleDFS(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {
            if (detectCycleDFS(i, -1, vis, adj))
                return true;
        }
    }
    return false;
}

// .............................//................//.....................................

bool BipartiteBFS(int src, int color[], vector<int> adj[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
}
bool CheckBipartiteBFS(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!BipartiteBFS(i, color, adj))
                return false;
        }
    }
    return true;
}

// .............................//................//.....................................

bool BipartiteDFS(int src, int color[], vector<int> adj[])
{
    if (color[src] == -1)
        color[src] = 1;
    for (auto it : adj[src])
    {
        if (!color[it])
        {
            color[it] = 1 - color[src];
            if (!BipartiteDFS(it, color, adj))
                return false;
        }
    }
    return true;
}
bool CheckBipartiteDFS(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!BipartiteDFS(i, color, adj))
                return false;
        }
    }
    return true;
}

// .............................//................//.....................................

bool checkCycleDFS(int node, int vis[], int dfsvis[], vector<int> adj[])
{
    vis[node] = 1;
    disvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            if (checkCycleDFS(it, vis, dfsvfs, adj))
                return true;
        }
        else if (disvis[it])
        {
            return true;
        }
    }
    disvis[node] = 0;
    return false;
}
bool checkCycleinDirectedGraphUsingDFS(int V, vector<int> adj[])
{
    int vis[n], dfsvis[n];
    memset(vis, 0, sizeof(vis));
    memset(dfs, 0, sizeof(dfsvis));
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkCycleDFS(i, vis, dfsvis, adj))
            {
                return true;
            }
        }
    }
    return false;
}
// .....................//...............//....................//..............//.......

// We are using topological sort logic to detect a cycle using BFS,
// as topological sort can only be generated for DAS i.e. Directed Acyclic Graph
// So if we are not able to generate a topological sort for a given graph we conclude that there is no cycle

bool checkCycleinDirectedGraphUsingBFS(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(n, 0);

    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (cnt == n)
    {
        return false;
    }
    return true;
}
// ....................//................//...................//..............//.......

void findTopoDFS(int node, vector<int> vis[], stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findTopoDFS(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> TopologyDFS(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    stack<int> st;
    vector<int> topoSortDFS;
    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            findTopoDFS(i, vis, stack, adj);
        }
    }
    while (!st.empty())
    {
        topoSortDFS.push_back(st.top());
        s.pop();
    }
    return topoSortDFS;
}

// .............//..........//..........//...........//........//........//.........//..

vector<int> TopologyBFS(int n, vector<int> adj[])
{
    vector<int> indegree(n, 0);
    vector<int> topoSortBFS;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push[i];
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop;
        topoSortBFS.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topoSortBFS;
}

// ...........//..........//................//...........//..........//............//......
void shortestDistanceBFS(int n, vector<int> adj[], int src)
{
    vector<int> dis(n, INT_MAX);
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dis[node] + 1 < dis[it])
            {
                dis[it] = dis[it] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dis[it] << " "
    }
}
// ............//..............//...........//............//.........//............//...
void findTopoDFSforWeightedGraph(int node, vector<int> vis[], vector<pair<int, int>> &adj, stack<int> st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findTopoDFSforWeightedGraph(it, vis, adj, st);
        }
        st.push(it);
    }
}
void shortestDistanceWeigthedDFS(int n, vector<pair<int, int>> &adj, int src)
{
    vector<int> vis(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            findTopoDFSforWeightedGraph(i, vis, adj, st)
        }
    }

    vector<int> dis(n, INT_MAX)
        dis[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dis[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])
                {
                    dis[it.first] = dis[node] + it.second;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
}
// ...........//..........//................//...........//..........//............//....

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1] for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dfs = dfsofGraph(n, adj);
    vector<int> bfs = bsfofGraph(n, adj);

    bool CheckCycleBFS = CheckCycleBFS(n, adj);
    bool CheckCycleDFS = CheckCycleDFS(n, adj);

    bool CheckBipartiteBFS = CheckBipartiteBFS(n, adj);
    bool CheckBipartiteDFS = CheckBipartiteDFS(n, adj);

    bool checkCycleinDirectedGraphUsingDFS = checkCycleinDirectedGraphUsingDFS(n, adj);
    bool checkCycleinDirectedGraphUsingBFS = checkCycleinDirectedGraphUsingBfs(n, adj);

    vector<int> TopologyDFS = TopologyDFS(n, adj);
    vector<int> TopologyBFS = TopologyBFS(n, adj);

    int k, l;
    cin >> k >> l;
    vector<pair<int, int>> newAdj[k] for (int i = 0; i < l; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        newAdj[u].push_back({w, wt});
    }

    int sourceOfTraversal;
    cin >> sourceOfTraversal;

    shortestDistanceWeigthedDFS(k, newAdjdj, sourceOfTraversal);
    shortestDistanceBFS(n, adj, sourceOfTraversal);

    DijsktraAlgo(k, newAdj, sourceOfTraversal);

    return 0;
}