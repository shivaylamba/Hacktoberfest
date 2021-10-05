class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len= nums.size();
        int count=0;
        for(int i = 0 ; i < nums.size(); i++){
        if(nums[i]==val) {
            count++;
         }
         else
            nums[i-count]=nums[i];
         }
          
         return len - count;
    }
};
//
// while(find(nums.begin(), nums.end(),val)!=nums.end())
// 	nums.erase(nums.begin(),nums.end(),val);
// return nums.size();