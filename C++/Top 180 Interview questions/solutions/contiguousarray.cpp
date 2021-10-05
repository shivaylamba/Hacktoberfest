class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n  = nums.size();
       for(int i = 0 ; i < n ; i++)
       {
       if(nums[i]==0)
           nums[i] = -1;
       }
        // now the problem turns out to be maximum subbary sum of 0
        // can I use maps?
        unordered_map<int,int> um;
        int sum = 0;
        int res = 0;
        for(int i = 0 ; i< n ; i++)
        {
          sum+=nums[i];
          if(sum==0)
              res = i + 1;
          else
          {
              if(um.find(sum)!=um.end())
                  res = max(res,i- um[sum]);
              else
                  um[sum] = i;
          }
        }
        return res;
    }
};