class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();

        vector<pair<int, int>>v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }

        sort(begin(v), end(v));
        
        int left=0, right=n-1;

        while(left<=right){
            if(v[left].first+v[right].first==target){
                ans.push_back(v[left].second);
                ans.push_back(v[right].second);
                break;
            }

            if(v[left].first+v[right].first<target)left++;
            else right--;
        }

        return ans;
    }
};
