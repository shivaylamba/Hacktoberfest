/*
Minimum Cost Path
Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  
Examples :
Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
Expected Time Complexity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 500
*/

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
         int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<int> d={0,1,0,-1,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                int x=it.second.first+d[i];
                int y=it.second.second+d[i+1];
                if(x<0 || y<0 || x==n || y==n)continue;
                int dis=it.first+grid[x][y];
                if(dis<dist[x][y]){
                    pq.push({dis,{x,y}});
                    dist[x][y]=dis;
                }
            }
        }
        return dist[n-1][n-1];
    }
};