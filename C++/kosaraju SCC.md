#### Kosaraju algorithm
- first we traverse the graph using gfs, and while returning from any node, we insert them into stack, so we have elements inserted in reverse order of tracersal
- then what we do is take transpose of the graph (as graph is directed)
- then in that new graph, we have our forest and no different trees in there gives final answer 

![SCC](https://user-images.githubusercontent.com/62437314/130319325-50c1a2b8-d818-482c-adf2-5445cc98ef41.png)


```cpp
// step 1: grpah traversal, and stack fill order
void dfs(int x, vector<int> adj[], bool vis[], stack<int> &s) {
	    vis[x]=true;
	    for(auto i : adj[x]){
	        if(!vis[i])
	            dfs(i, adj, vis, s);
	    }
	    s.push(x);
}

// for traversal for each tree
	void dfs2(int x, vector<int> adj2[], bool vis[]){
	    vis[x]=true;
	    for(auto i : adj2[x]){
	        if(!vis[i])
	            dfs2(i,adj2,vis);
	    }
	}
  
//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        stack<int> s;
        bool vis[v+1];
        
        // first graph traversal to push all nodes to stack
        memset(vis,false, sizeof(vis));
        for(int i=0;i<v;i++){
            if(!vis[i])
                dfs(i, adj, vis, s);
        }
        
        // transpose of graph
        vector<int> adj2[v+1];
        for(int i=0;i<v;i++){
            for(auto j : adj[i]){
                adj2[j].push_back(i);
            }
        }
        
        // next traversal
        memset(vis,false, sizeof(vis));
        int ans = 0;
        while(s.empty()==false){
            int x = s.top();
            // cout<<"v: "<<x<<endl;
            s.pop();
            if(!vis[x]){
                dfs2(x,adj2,vis);
                ans++;
            }
        }
        return ans;
        //code here
    }
```
