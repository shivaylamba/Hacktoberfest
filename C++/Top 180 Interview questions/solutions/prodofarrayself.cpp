class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count_0 = 0;
        int prod_nonzero = 1;
        int prod = 1;
        vector<int> ans(n);
        for(auto it : nums)
        {
        prod*=it;
        if(it==0)
            count_0++;
        else
            prod_nonzero*=it;
        }
        if(count_0 == 1)
        {
            for(int i = 0 ; i < n ; i++)
                if(nums[i]==0)
                    ans[i]= prod_nonzero;
        }
        else if(count_0==0)
        {
           for(int i = 0 ; i < n ; i++) 
               ans[i] = prod / nums[i];
        }
    
        return ans;
        
    }
};