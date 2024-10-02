/*
164. Maximum Gap
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
*/
//  using the Counting Sort
// Most Optimized Approach 
//  Time complexity O(n)
//  Space complexity O(n)
class Solution {
public:
vector<int> countsort(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> m;
    for (int i = 0; i < n; i++ )
        m[nums[i]]++;

    nums.clear();
    for (auto it : m)
    {
        int cnt = it.second;
        while (cnt--)
        {
            nums.push_back(it.first);
        }
    }
    return nums;
}

int maximumGap(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;
    vector<int> sortednums = countsort(nums);

    int maxgap = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        int currgap = sortednums[i] - sortednums[i - 1];
        maxgap = max(maxgap, currgap);
    }

    return maxgap;
}
};
//  using the inbilt sorting function 
class Solution {
public:
// Optimized Approach 
//  Time complexity O(n*log(n))
//  Space complexity O(1)
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return 0;
        else if(nums.size()==2) return abs(nums[0]-nums[1]);
        else{
            int maxa = INT_MIN;
            for(int i=0;i<nums.size()-1;i++){
                  maxa = max(maxa,abs(nums[i]-nums[i+1]));
            }
            return maxa;
        }
    }
};
