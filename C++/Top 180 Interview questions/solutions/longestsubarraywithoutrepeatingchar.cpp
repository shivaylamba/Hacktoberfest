class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        unordered_map<char, int> mpp;
        int left = 0;
        int right = 0;
        int n = s.length();
        while(right < n)	
        {
            if(mpp.find(s[right])!=mpp.end())
            {
                left = max(mpp[s[right]] + 1,left);
            }
                mpp[s[right]]=right;
                len = max(len, right - left + 1);
                right++;
        }
        return len;
    }
};