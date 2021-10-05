class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        // initializing the vector with 2^n;
        // 1 << n means that only
        // not using power operator saves time
        for (int i=0; i<(1<<n); i++) 
            ans[i] = i^(i>>1);
        return ans;
    }
};