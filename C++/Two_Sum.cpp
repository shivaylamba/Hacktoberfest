//QUESTION- https://leetcode.com/problems/two-sum/

// We use concept of hashing to solve this question.

//CODE- 

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];  //we fix one number
            int y=target-x; // then search the other in map
            if(map.find(y)!=map.end() && i!=map[y])
            {
                ans.push_back(i);
                ans.push_back(map[y]);
                break;
            }
            else
            {
                map[nums[i]]=i;
            }
        }
        
        return ans;
    }

int main()
{
    int n; 
    cin>> n;

    int target;
    cin>>target;

    vector<int>nums(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    vector<int> ans= twoSum(nums,target);

    cout<<ans[0]<<" "<<ans[1];
    
}
