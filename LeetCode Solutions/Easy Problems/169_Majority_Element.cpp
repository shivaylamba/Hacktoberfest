/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(count == 0) {
                candidate = nums[i];
            }
            if(nums[i] == candidate) {
                ++count;
            }else{
                --count;
            }
        }
        return candidate;
    }
    int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int ,int> f;
	for(int i=0;i<n;i++){
		f[arr[i]]++;
	}
	int majele=-1;
	int majn =floor(n/2);
	for(auto i:f ){
		if(i.second>majn){
			majn =  i .second;
			majele=i.first;
		}
	}
	return majele;
}
};