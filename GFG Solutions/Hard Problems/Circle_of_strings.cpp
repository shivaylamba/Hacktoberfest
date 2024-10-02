/*
Circle of strings
Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.
For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"
Examples
Input: arr[] = ["abc", "bcd", "cdf"]
Output: 0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.
Input: arr[] = ["ab" , "bc", "cd", "da"]
Output: 1
Explaination: These strings can form a circle of strings.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
Constraints: 
1 ≤ length of strings ≤ 20
*/

class Solution {
  public:
    private:
    
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        
        vis[node] = 1;
        
        for(auto &adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis);
            }
        }
        
    }
    
    public:
    
    int isCircle(vector<string> &arr) {
        
        int n = arr.size();
        vector<int> adj[26];
        vector<int> inDeg(26, 0), outDeg(26, 0);
        for(auto it : arr){
            int u = it[0] - 'a';
            int v = it[it.size() - 1] - 'a';
            adj[u].push_back(v);
            inDeg[v]++;
            outDeg[u]++;
        }
        for(int i=0; i<26; i++){
            if(inDeg[i] != outDeg[i])
               return 0;
        }
        vector<int> vis(26, 0);
        dfs(arr[0][0] - 'a', adj, vis);
        for(int i=0; i<26; i++){
            if(inDeg[i] and !vis[i])
               return 0;
        }
        
        return 1;
        
    }
};