#1915 Binary Search Leetcode problems 
[Leetcode link](https://leetcode.com/problems/binary-search/)
[Solution](https://github.com/Mahikolhe23/LeetCode/tree/main/0704-binary-search)

class Solution {
    public int search(int[] nums, int target) {
        int s=0;
        int e=nums.length-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target)
                return m;
            if(nums[m]<target)
                s=m+1;
            else
                e=m-1;
        }
        return -1;
    }
}


