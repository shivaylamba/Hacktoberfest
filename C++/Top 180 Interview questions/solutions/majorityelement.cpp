class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        n = floor(n/2);
        unordered_map<int,int> um;
        for(int i = 0 ; i < nums.size() ; i++){
            um[nums[i]]++;
        }
        unordered_map<int,int>::iterator it;
        for(it = um.begin(); it!=um.end(); it++)
        {
        if(it->second > n)
            return it->first;
        }
        return 0;
    }
};