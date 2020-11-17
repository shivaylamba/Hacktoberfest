#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000

const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

// Q.Given a 2D array of integers with ones representing land and zeroes representing water,
//return the number of islands in the grid

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isSafe(int x, int y, bool visited[5][5], int arr[5][5], int row = 5, int col = 5)
{
    if (x >= 0 && y >= 0 && y < col && x < row && visited[x][y] == 0 && arr[x][y] == 1)
        return true;
    return false;
}

void dfs(int x, int y, int arr[5][5], bool vis[5][5])
{
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dx[i], y1 = y + dy[i];
        if (isSafe(x1, y1, vis, arr))
            dfs(x1, y1, arr, vis);
    }
}

int main()
{
    int arr[5][5] = {{0, 0, 1, 0, 0},
                     {0, 0, 0, 1, 0},
                     {0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 1},
                     {0, 0, 0, 1, 0}};

    int count = 0;

    bool vis[5][5];

    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 1 && !vis[i][j])
            {
                dfs(i, j, arr, vis);
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
