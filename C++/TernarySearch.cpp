class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid1=l+(r-l)/3;
            int mid2=r-(r-l)/3;
            if(nums[mid1]==target)
                return mid1;
            if(nums[mid2]==target)
                return mid2;
            if(target<nums[mid1])
                r=mid1-1;
            else if(target>nums[mid2])
                l=mid2+1;
            else{
                l=mid1+1;
                r=mid2-1;
            }
        }
        return -1;
    }
};
