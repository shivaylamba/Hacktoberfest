class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 0 ; i< nums.size(); i++)
        {
            if(nums[i]!=0)
                nums[j++]=nums[i];
        }
        for(; j < n; j++)
            nums[j]=0;
    }
};// the relative order is maintained here