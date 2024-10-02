/*
You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

 

Example 1:

Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
Example 2:

Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104
*/
/*
Approach
Initialization: Obtain the size of the input array nums and create a result array of the same size.
int n = nums.size();

vector<int> result(n);

Prefix and Suffix Sums: Create two additional arrays, prefixSum and suffixSum, to store the cumulative sums from the beginning and end of the nums array, respectively. Initialize the first element of both arrays -Don't forget that the input array is sorted- .
vector<int> prefixSum(n), suffixSum(n);
prefixSum[0] = nums[0];
suffixSum[n - 1] = nums[n - 1];

Calculate Sums in One Loop: Use a single loop to calculate both the prefix and suffix sums simultaneously.
for (int i = 1; i < n; ++i) {
    prefixSum[i] = prefixSum[i - 1] + nums[i];
    suffixSum[n - i - 1] = suffixSum[n - i] + nums[n - i - 1];
}
Calculate Absolute Differences: Iterate through the array and compute the absolute differences using the prefix and suffix sums.
for (int i = 0; i < n; ++i) {
    int currentAbsoluteDiff = ((nums[i] * i) - prefixSum[i]) + (suffixSum[i] - (nums[i] * (n - i - 1)));
    result[i] = currentAbsoluteDiff;
}
Return the calculated result array.
Complexity
Time complexity: O(N)O(N)O(N)
Since we are looping over the input array two time, one time to calculate prefix and suffix arrays and another time to calculate the result which costs us 2 * N so time complexity is O(N).
Where N is the size of the input array.
Space complexity: O(N)O(N)O(N)
Since are storing two arrays of the same length of the input array which are the prefix and suffix arrays which costs us 2 * N so space complexity is O(N).
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefixSum(n), suffixSum(n);
        
        // Calculate and initialize the prefix sums & suffixSum array
        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];
        
        // Calculate the prefix sums & suffixSum array in one loop
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
            suffixSum[n - i - 1] = suffixSum[n - i] + nums[n - i - 1];
        }
        
        // Calculate absolute differences and update the result array
        for (int i = 0; i < n; ++i) {
            int currentAbsoluteDiff = ((nums[i] * i) - prefixSum[i]) + (suffixSum[i] - (nums[i] * (n - i - 1)));
            result[i] = currentAbsoluteDiff;
        }
        
        return result;
    }
};
class Solution {
public:
// Time Complexity O(n^2)
//  Space Complexity O(n)
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
     vector<int> ans;
     int i =  0 ;
     while(i<nums.size()){
         int ans2 = 0 ;
         for(int j = 0 ; j <nums.size();j++){
         ans2+=abs(nums[i]-nums[j]);
         }
     ans.push_back(ans2);
     i++;
     }
return ans;
    }
};