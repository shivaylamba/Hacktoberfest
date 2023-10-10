#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i : times){
            adj[i[0]].push_back({i[1],i[2]}); // {destination,weight}
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[k]=0;
        pq.push({k,0});
        
        while(!pq.empty()){
            int node =pq.top().first;
            int dist = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                if(it.second + dis[node] < dis[it.first]){
                    dis[it.first]=it.second + dis[node];
                    pq.push({it.first,dis[node]+it.second});
                }
            }
        }

        int ans=-1;
        for(int i=1;i<=n;i++)
            {
              if(dis[i]==INT_MAX) return -1;
              ans=max(ans,dis[i]);
          }
        return ans;

    }
};