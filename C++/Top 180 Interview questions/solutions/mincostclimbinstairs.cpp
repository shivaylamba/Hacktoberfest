class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      if(n==0)
          return 0;
      else if(n==1)
          return cost[0];
      else if(n == 2)
          return min(cost[0],cost[1]);
      for(int i = 2 ; i < n ; i++)
          cost[i] = cost[i] + min(cost[i-1],cost[i-2]);
      return min(cost[n-1],cost[n-2]);
    }
};