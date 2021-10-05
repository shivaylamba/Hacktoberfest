class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high)
    {
        int revcount=0;
        int j = mid;
        // as this is vector we won't be initializing the other i and k
        // we need to iterate in both the loops
        for(int i = low ; i <=mid-1 ; i++ )
        {
            // declaring 2 as long long
            while(j<=high && nums[i] > 2LL * nums[j])
                j++;
             revcount+=(j-mid);
             // j remains at the same position
        }
        vector<int> temp;
        int left = low;
        int right=mid;
        while(left <= mid-1 && right <= high)
        {
            if(nums[left]<=nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while(left<=mid-1)
            temp.push_back(nums[left++]);
        while(right<=high)
            temp.push_back(nums[right++]);
        for(int i = low ; i <=high; i++)
            nums[i]= temp[i-low];
        return revcount;
    } 
    int mergesort(vector<int>& nums, int low, int high)
    {
        if(low >= high) return 0;
            int mid = low + (high- low)/2;
            int count = mergesort(nums,low,mid);
            count+=mergesort(nums,mid+1,high);
            count+=merge(nums,low,mid+1,high);
            return count;
    }
    int reversePairs(vector<int>& nums) {
    return mergesort(nums,0, nums.size()-1);
    }
};