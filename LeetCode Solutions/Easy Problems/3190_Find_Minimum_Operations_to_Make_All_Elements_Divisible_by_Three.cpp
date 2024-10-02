/*
3190. Find Minimum Operations to Make All Elements Divisible by Three
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.
Return the minimum number of operations to make all elements of nums divisible by 3.
Example 1:
Input: nums = [1,2,3,4]
Output: 3
Explanation:
All array elements can be made divisible by 3 using 3 operations:
Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.
Example 2:
Input: nums = [3,6,9]
Output: 0
Constraints:
1 <= nums.length <= 50
1 <= nums[i] <= 50
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%3 == 0) continue;
            ans++;
        }
        return ans;
    }
};
//-----------------------------------------------------------------------------------------------------//
class Solution {
    public int minimumOperations(int[] nums) {
        int count = 0;
        for (int num : nums) {
            if (num % 3 != 0) {
                count++;
            }
        }
        return count;
    }
}
//----------------------------------------------------------------------------------------------------//
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0;
        for(int i:nums){
            if(i%3!=0){
                if((i-1)%3==0 || (i+1)%3==0 ) op++;
            }
        }
        return op;
    }
};