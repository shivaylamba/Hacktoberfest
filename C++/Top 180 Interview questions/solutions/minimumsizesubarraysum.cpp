class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int len= INT_MAX;
        int left = 0;
        int currSum=0;
        int n = nums.size();
        for(int i= 0 ; i< n; i++){
        currSum+=nums[i];
            while(currSum >=target){
                len=min(len,i-left+1);
                
                currSum-=nums[left];
                left++;
            }
        }
        return (len!=INT_MAX) ? len : 0;
    }
};