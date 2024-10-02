class Solution {
    public int search(int[] nums, int target) {
        int s=0;
        int e=nums.length-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                s= mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
}
