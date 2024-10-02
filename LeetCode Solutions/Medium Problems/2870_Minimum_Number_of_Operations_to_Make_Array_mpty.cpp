/*
2870. Minimum Number of Operations to Make Array Empty
You are given a 0-indexed array nums consisting of positive integers.
There are two types of operations that you can apply on the array any number of times:
Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

Example 1:
Input: nums = [2,3,3,2,2,4,2,3,4]
Output: 4
Explanation: We can apply the following operations to make the array empty:
- Apply the first operation on the elements at indices 0 and 3. The resulting array is nums = [3,3,2,4,2,3,4].
- Apply the first operation on the elements at indices 2 and 4. The resulting array is nums = [3,3,4,3,4].
- Apply the second operation on the elements at indices 0, 1, and 3. The resulting array is nums = [4,4].
- Apply the first operation on the elements at indices 0 and 1. The resulting array is nums = [].
It can be shown that we cannot make the array empty in less than 4 operations.
Example 2:

Input: nums = [2,1,2,2,3,3]
Output: -1
Explanation: It is impossible to empty the array.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= 106
*/
// OPtimized Approach (using unordered map)
// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans =0;
        unordered_map<int,int> f;
        for(auto i:nums){
               ++f[i];
        }
        for(auto i:f){
            if(i.second==1){return -1;}
            if(i.second%3==0){
                ans+=i.second/3;
            }
            else if(i.second%3==2){
                ++ans;
            ans+=(i.second-2)/3;
            }
            else{
                ans+=2;
                ans+=(i.second-4)/3;
            }
        }
        return ans;
    }
};
// Approach-2 // Most Optimized Approach
/*
Approaches
(Also explained in the code)
=>It uses a map mp to calculate the frequency of each number in nums.
=>If any number occurs only once in nums, it's impossible to achieve the desired pattern, so the function returns -1.
=>It calculates the number of moves needed to make all occurrences of each number a multiple of 3. If there are remaining occurrences 
(not divisible by 3), it adds one more move for each such occurrence.
=>Finally, it returns the total number of moves needed to achieve the desired pattern.

Complexity
Time complexity:
O(n)
Space complexity:
O(n)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a: nums){
            mp[a]++;
        }

        int count=0;
        for(auto a: mp){
            int t = a.second;
            if(t==1)return -1;
            count += t/3;
            if(t%3)count++;
        }
        return count;
    }
};

