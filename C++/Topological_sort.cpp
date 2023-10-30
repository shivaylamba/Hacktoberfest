// C++ Program for topological sort using BFS

#include <bits/stdc++.h>
using namespace std;

bool topological_sort(int n, vector<int> adj[], vector<int> ans)
{

    vector<int> indegree(n, 0);

    for (int i = 0; i < adj.size(); i++)
        indegree[adj[i][1]]++;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    if (!q.empty())
        return false;

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto it : adj[node])
        {

            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] != 0)
            return false;
    }

    return true;
}

// Driver program to check above functions
int main()
{
    int n, e; // Input for no. of nodes and edges
    cin >> n >> e;

    vector<int> adj[n];
    int u, v;

    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> ans;

    bool check = topological_sort(n, adj, ans); // Calling function for topological sort

    if (check == false)
        cout << "Not Possible\n";
    else
    {
        for (auto it : ans)
            cout << it << " ";
    }
    cout << endl;

    return 0;
}
