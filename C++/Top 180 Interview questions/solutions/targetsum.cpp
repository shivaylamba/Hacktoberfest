class Solution {
public:
    
int subsetsum(vector<int> &A, int B) {
 int n = A.size();
 int sum = B;
 int t[n+1][sum + 1];
 for(int i = 0 ; i< sum + 1 ; i++)
    t[0][i] = 0;
for(int i = 0 ; i< n + 1 ; i++)
    t[i][0] = 1;
 for(int i = 1 ; i<n+1 ; i++)
 {
     for(int j = 1; j < sum+1 ; j++)
     {
         if(A[i-1]<=j)
             t[i][j] = t[i-1][j- A[i-1]] + t[i-1][j];
         else
            t[i][j] = t[i-1][j];
     }
 }
 return t[n][sum];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            int beb = nums[0];
            if(beb==abs(target))
                return 1;
            else
                return 0;
        }
        int diff = target;
        int sum = 0;
        for(auto it : nums)
            sum+=it;
        int rem = (diff + sum)/2;
        return subsetsum(nums,rem);
    }
};