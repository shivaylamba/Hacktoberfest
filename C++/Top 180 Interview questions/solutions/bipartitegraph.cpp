class Solution {
public:
    bool bipartitite(int node, vector<vector<int>>& graph, vector<int>& color)
    {
        if(color[node]==-1)
            color[node] = 1;
        for(auto it : graph[node])
        {
            if(color[it]==-1){
                color[it] = color[node] - 1;
                if(!bipartitite(it,graph,color))
                    return false;
            }
                else if(color[it]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // gives us number of vertices / nodes
        vector<int> color(n,-1);
        for(int i = 0 ; i < n; i++)
        {
            if(color[i]==-1)
            {
                if(!bipartitite(i,graph,color))
                    return false;
            }
        }
        return true;
        // this is done using dfs search
    }
};