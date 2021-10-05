class Solution {
public:
    
    void func(int ind, vector<vector<int>>& ans, vector<int>& ds, int target, vector<int>& arr)
    {
         if(target==0){
             ans.push_back(ds);
         return;       
         }
        for(int i = ind ; i < arr.size(); i++)
        {
            if(i>ind &&(arr[i]==arr[i-1])) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            func(i+1,ans,ds,target-arr[i],arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        func(0,ans,ds,target,arr);
        return ans;
    }
};