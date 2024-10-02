/*
1679. Max Number of K-Sum Pairs
You are given an integer array nums and an integer k.
In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
Return the maximum number of operations you can perform on the array.
Example 1:
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/
/*
    USING HASH TABLE
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> map;
        int count=0;
        for(int i:nums){
            if(map[k-i]){
                map[k-i]--;
                count++;
            }
            else map[i]++;
        }
        return count ;
    }
};
/*
    USING SORTING and TWO-POINTER
Time Complexity O(n*log(n))
Space Complexity O(1)
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.size()==0 || nums.size()==1){return 0;}
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0 , j = n-1 ,count=0;
        while(i<j){
            int elemenet = nums[i]+nums[j];
            if(elemenet==k){count++;i++;j--;}
            else if(elemenet>k){j--;}
            else{i++;}
        }
        return count;
    }
};