class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0 || n==1)
            return n;
        vector<int> arr(n + 1);
        arr[0] = 0;
        arr[1] = 1;
        int maxi = 1;
        for(int i = 2 ; i < n + 1 ; i++)
        {
            arr[i] = i & 1 ? arr[i >> 1] + arr[(i >> 1) + 1] : arr[i >> 1];
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
};