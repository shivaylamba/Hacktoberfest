/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Complexity of this function is O(nlog(n)) + O(n) => O(nlog(n)) 
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return {-1};
        }
        vector<int> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
            v.push_back(nums[i]);
            i++;
            }
        }
        return v;
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(auto x:s.findDuplicates(nums)){
        cout<<x<<"\t";
}
}