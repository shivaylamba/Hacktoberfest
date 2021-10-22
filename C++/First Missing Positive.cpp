class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        set<int>s;
        int c=0;
        if(nums.size()==0)
        {
            return 1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                s.insert(nums[i]);
            }
        }
        for(int i=1;i<=nums.size()+1;i++)
        {
            if(s.find(i)==s.end())
            {
                c=i;
                return c;
            }
        }
        return 0;
    }
};
