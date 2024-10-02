/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Brute Force O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
           for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                  return {i,j};
            }
           }
        }
    return {};
    }
    // Login_approach O(nlog(n));
vector<pair<int,int>> twoSumPair(vector<int>& arr, int target, int n)
{
	// Write your code here. 
	vector<pair<int,int>> output ;
	sort(arr.begin(),arr.end());

      int i =0;
            int j = n - 1;
            while (i<j) {
				pair<int,int> p;
                int sum = arr[i] + arr[j];
                if (sum == target) {
                    p.first = arr[i];
					p.second = arr[j];
                    output.push_back(p);
                    i++;
                    j--;
                } else if (sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
       if(!output.size()){
           output.push_back({-1,-1});
       }
       return output;
}
//          using the Hash map
    vector<int> twoSumHashMap(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
       
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }
 
        return {-1, -1};
    }
// Most Optimized
vector<int> twoSumOptimized(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numsWithIndices;
        for(int i=0; i<n; i++)
            numsWithIndices.push_back({nums[i], i});

        sort(numsWithIndices.begin(), numsWithIndices.end());

        int left = 0, right = n-1;
        while (left < right)
        {
            int currentSum = numsWithIndices[left].first + numsWithIndices[right].first;
            if(currentSum == target)
                return {numsWithIndices[left].second, numsWithIndices[right].second};
            else if(currentSum < target)
                left++;
            else
                right--;
        }
        return {-1, -1};
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
  vector<int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int target;
cin>>target;
for(auto x:s.twoSum(arr,target)){
    cout<<x<<" ";
}
vector<pair<int,int>> res = s.twoSumPair(arr,target,n);
for(auto p:res){
    cout<<p.first<<":"<<p.second<<endl;
}
return 0;
}