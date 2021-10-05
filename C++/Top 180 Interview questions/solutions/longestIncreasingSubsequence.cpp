class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int> res;
       res.push_back(nums[0]);
       for(int i = 1 ; i < nums.size(); i++)
       {
           // you can access the back element in the vector
           if(res.back() < nums[i])
               res.push_back(nums[i]);
           else
           {
               int ind = lower_bound(res.begin(), res.end(),nums[i]) - res.begin();
               res[ind] = nums[i];
           }
           // storing the minimum value so that we can keep the next bigger values
       }
        return res.size();
    }
};