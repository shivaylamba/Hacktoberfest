#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        deque<int>dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<=i-k)dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i])dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    int k;
    cin>>k;
    vector<int> arr=s.maxSlidingWindow(nums,k);
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";  
    }
    return 0;  
}