class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int len=0;
        int n = s.size();
        vector<int> res(256,-1);
        // it will change the value according to the ascii value of the character
        int right=0;
        int left=0;
        while(right < n){
            if(res[s[right]]!=-1) left= max(res[s[right]] +1 , left);
            res[s[right]]=right;
            len= max(len, right-left+1);
            right++;
        }
        return len;
    }
};