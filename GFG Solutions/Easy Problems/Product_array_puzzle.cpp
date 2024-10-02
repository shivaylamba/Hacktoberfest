/*
Product array puzzle
Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].
Example 1:
Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Example 2:
Input:
n = 2
nums[] = {12,0}
Output:
0 12
Your Task:
You do not have to read input. Your task is to complete the function productExceptSelf() that takes array nums[] and n as input parameters and returns a list of n integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
Constraints:
1 <= n <= 1000
0 <= numsi <= 200
Array may contain duplicates.
*/
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int p = 1 , pwz = 1 , count =0;
        for(long long int i:nums){
            if(i) pwz*=i;
            if(!i) count++;
            p*=i;
        }
        if(count>1){
            for(long long int i = 0 ;i<nums.size();i++) nums[i] = 0;
            return nums;
        }
        for(int i = 0  ;i<nums.size();i++){
            if(nums[i]==0) nums[i] =pwz;
            else nums[i] = p/nums[i];
        }
        return nums;
    }
};
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //code here        
        long long int withz = 1 , woz = 1;
        int count = 0;
        for(int i =0;i<n;i++){
            if(nums[i]){
                woz*=nums[i];
            }
            if(!nums[i]){count++;};
              withz *= nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(count<2){
                if(nums[i]){    nums[i] = withz/nums[i];    }
            else{  nums[i] = woz;  }
            }
            else{ nums[i] = 0;  }
        }
        return nums;
    }
};
