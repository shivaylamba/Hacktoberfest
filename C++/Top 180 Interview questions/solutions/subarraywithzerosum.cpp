class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longeststreak=0;
        set<int> s;
        for (int i = 0 ; i < n ; i++)
        {
            s.insert(nums[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(s.count(nums[i]-1)==0)
            {
                int currentnumber = nums[i];
                int currentstreak = 1;
                
                while(s.count(currentnumber + 1))
                {
                    currentnumber++;
                    currentstreak++;
                }
                longeststreak = max(longeststreak, currentstreak);
            }
        }
        return longeststreak;
    }
};