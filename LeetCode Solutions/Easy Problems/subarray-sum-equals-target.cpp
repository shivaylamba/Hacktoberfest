/*
DP return subarray start and end indexes of the sum == target 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
           int sum=0;
           for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum==target){
                nums.clear();
                nums.push_back(i);
                nums.push_back(j);
                break;
            }
           }
        }
        return nums;
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
return 0;
}