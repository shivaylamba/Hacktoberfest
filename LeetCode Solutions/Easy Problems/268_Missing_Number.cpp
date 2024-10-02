/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int esum =n*(n+1)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return esum -sum;
    }
};
//  Time Complexity: O(n)
//  Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n=nums.size();
      int temp=0;
      int cons=0;
      //executing a loop of n numbers from 1 to n+1 so that it covers the last number in given array
      for(int i=1;i<n+1;i++){
          //adding the numbers from one to n+1
          temp=temp+i;
      }
      //executing a loop on n numbers from 0 to n
      for(int j=0;j<n;j++){
          // adding all the numbers in the given array
          cons=cons+nums[j];


      }
      // question asks for the missing numbers from 0 to n and the last number in array is the nth number....so the approach is to add all the numbers of given array size(temp) and subtract it from the sum of given array numbers(cons)which will result the misssing number 
      int mm=temp-cons;
      return mm;
        
    }
};
//  Time Complexity: O(n)
//  Space Complexity: O(1n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> ans(nums.size()+1,0);
        for(int i = 0 ; i<nums.size();i++){
            ans[nums[i]]++;
        }
        for(int i = 0 ; i <ans.size();i++){
            if(ans[i]==0){
                return i;
            }
        }
        return -1;
    }
};
