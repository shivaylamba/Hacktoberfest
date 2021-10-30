/* What does the following program does ?

A directed graph is strongly connected if there is a path between all pairs of vertices. A
strongly connected component (SCC) of a directed graph is a maximal strongly connected
subgraph. For example, there are three SCCs in the following graph. Given a directed graph,
write a program that prints the components and their associated vertices. Also, 
write a program that prints the components of the component graph in a topologically sorted order.*/

// Tags: Graph, Topological Sorting, Strongly Connected Components, DFS

// To learn more: CLRS book

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
    int vertex;
    int time;
};

void DFS_visit(vector<int> v[], int n, int start, int visited[], int entry[], int exit[], int p[])
{
    // We are counting the entry and exit times of the node
    // so that we can sort the graph accordingly (Needed for toplogical Sorting)
    static int time = 0;
    time++;

    entry[start] = time;
    for(int i=0; i<v[start].size(); i++)
    {
        int temp = v[start][i];
        if(visited[temp] == 0)
        {
            visited[temp] = 1;
            p[temp] = start;
            DFS_visit(v, n, temp, visited, entry, exit, p);
        }
    }
    time++;

    exit[start] = time;    
}

bool compare(struct info a, struct info b)
{
    if(a.time > b.time)
    return true;

    return false;
}

void insert(vector<int> adj[], int a, int b)
{
    // Since the graph given is directed and unweighted
    // The edges are uni-directional in nature and therefore 
    // in the adjacency list, the vertex are being added to parent set
    adj[a].push_back(b);
}

void pgraph(vector<int> v[], int n)
{
    // This is a check on how the graph looks like via adjacency list representation
    for(int i=0; i<n; i++)
    {
        cout << i + 1 << " ->";
        for(int j=0; j<v[i].size(); j++)
        {
            cout << v[i][j] + 1 << " ->";
        }
        cout << "NULL" << endl;
    }
}

void final_DFS_visit(vector<int> v[], int n, int start, int visited[], int mark[], int count)
{
    for(int i=0; i<v[start].size(); i++)
    {
        int temp = v[start][i];
        if(visited[temp] == 0)
        {
            visited[temp] = 1;
            mark[temp] = count;
            cout << temp + 1 << " "; 
            final_DFS_visit(v, n, temp, visited, mark, count);
        }
    }
}

void ultimate_DFS(vector<int> v[], int n, int mark[], int original)
{
    // Topological Sort on Final Graph
    int parent[n];
    int visited[n] = {0};
    int entry[n] = {-1};
    int exit[n] = {-1};
    for(int i=0; i<n; i++)
    {
        if(visited[i] == 0)
        {
            parent[i] = -1;
            visited[i] = 1;
            DFS_visit(v, n, i, visited, entry, exit, parent);
        }
    }

    // Exit array has the exit times
    struct info a[n];
    for(int i=0; i<n; i++)
    {
        a[i].vertex = i;
        a[i].time = exit[i];
    }

    sort(a, a+n, compare);

    cout << endl << "Topological Sort: " << endl;
    cout << "(";
    for(int i=0; i<n; i++)
    {
        int node_mark = a[i].vertex;
        cout << "( ";
        for(int j=0; j<original; j++)
        {
            if(mark[j] == node_mark + 1)
            {
                cout << j + 1 << " ";                
            }
        }

        if(i != n-1)
        cout << "), " ;
        else
        cout << ")" ; 
    }
    cout << ")" << endl;
}

void final_DFS(vector<int> v[], struct info d[], int n, vector<int> real[])
{
    int mark[n];
    int count = 1;
    int visited[n] = {0};
    for(int i=0; i<n; i++)
    {
        int start = d[i].vertex;
        if(visited[start] == 0)
        {
            cout << "Component " << count << ": " << start + 1 << " ";
            visited[start] = 1;
            mark[start] = count;
            final_DFS_visit(v, n, start, visited, mark, count);
            count++;
            cout << endl;
        }
    }

    int total = count - 1;
    // We have to do topological sorting on SCC's 
    int x[total][total] = {0};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<real[i].size(); j++)
        {
            int s = i;
            int d = real[i][j];
            if(mark[s] == mark[d])
            continue;
            else
            {
                int t1 = mark[s] - 1;
                int t2 = mark[d] - 1;
                x[t1][t2] = 1;
            }
        }
    }

    vector<int> final_graph[total];
    // Print the final graph
    for(int i=0; i<total; i++)
    for(int j=0; j<total; j++)
    if(x[i][j] == 1)
    final_graph[i].push_back(j);

    ultimate_DFS(final_graph, total, mark, n);
    
}

void final(vector<int> v[], struct info d[], int n, vector<int> real[])
{
    final_DFS(v, d, n, real);
}

void DFS(vector<int> v[], int n)
{
    int parent[n];
    int visited[n] = {0};
    int entry[n] = {-1};
    int exit[n] = {-1};
    for(int i=0; i<n; i++)
    {
        if(visited[i] == 0)
        {
            parent[i] = -1;
            visited[i] = 1;
            DFS_visit(v, n, i, visited, entry, exit, parent);
        }
    }

    // Exit array has the exit times
    struct info d[n];
    for(int i=0; i<n; i++)
    {
        d[i].vertex = i;
        d[i].time = exit[i];
    }

    sort(d, d+n, compare);

    // Let us do transpose of the graph
    vector<int> v_transpose[n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            int source = i;
            int destination = v[i][j];
            v_transpose[destination].push_back(source);
        }
    }

    // Run DFS on transposed graph in the order of topological sorting
    final(v_transpose, d, n, v);
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<int> v[n];
    // adj is the adjacency list
    int a, b, count = 0;
    cout << "Directed Edges: " << endl;
    while(1)
    {
        cin >> a;
        if(a == -1)
        break;
        else
        {
            cin >> b;
            a--; b--;
            insert(v, a, b);
            count++;
        }
    }

    cout << endl;
    DFS(v, n); // Performing DFS in order to do the Topological Sorting of Graph
}   