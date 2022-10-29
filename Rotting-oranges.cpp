class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size(), sum=0, ans=0, days=0;
        
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                
                if(grid[i][j]!=0)
                    sum++;
            }
        }
        
        int dx[4]={0,1,-1,0};
        int dy[4]={1,0,0,-1};
        
        while(q.size()!=0)
        {
            int sz=q.size();
            
            ans+=sz;
            
            while(sz--)
            {
                int x=q.front().first, y=q.front().second;
            
                q.pop();

                for(int i=0;i<4;i++)
                {
                    if(x+dx[i]<0 || y+dy[i]<0 || x+dx[i]>=m || y+dy[i]>=n || grid[x+dx[i]][y+dy[i]]!=1) continue;
                    
                    grid[x+dx[i]][y+dy[i]]=2;
                    q.push({x+dx[i], y+dy[i]});
                }
            }
            if(q.size()!=0)
                days++;
        }
        
        return (sum==ans)?days:-1;
        
    }
};
