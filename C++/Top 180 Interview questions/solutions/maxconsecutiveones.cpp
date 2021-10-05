class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int res = 0;
        int maxres=0;
        for(auto it : nums)
        {
            if(it==0)
                res=0;
            else 
                res++;
            maxres= max(maxres,res);
        }
        return maxres;
    }
};