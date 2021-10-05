class Solution {
public:
    int majorityElement(vector<int>& nums) {
       // majority voting algorithm
        int val = nums[0];
        int count = 1;
        for(int i = 1 ; i < nums.size(); i++)
        {
            if(count ==0)
                val = nums[i];
            if(val==nums[i])
                count++;
            else
                count--;
        }
        return val;
    }
};