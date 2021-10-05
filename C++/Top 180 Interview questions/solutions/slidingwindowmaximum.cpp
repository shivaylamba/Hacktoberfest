class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // this question can be solved using double ended queue
        deque<int> d;
        int n = nums.size();
        vector<int> ans;
        if(k==0)
            return ans;
        // if we have to find maximum in 0 sized window we return empty vector
        for(int i = 0 ; i < n ; i++)
        {
            while(!d.empty() && d.front()<= i - k)
                d.pop_front();
            while(!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
            if(i >= k-1)
                ans.push_back(nums[d.front()]);                
        }
        return ans;
    }
};