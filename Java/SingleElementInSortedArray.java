class SingleElementInSortedArray {
    public int singleNonDuplicate(int[] nums) {
        int left = 0, right = nums.length - 1;
        while( left < right){
            int mid = (left + right) / 2;
            if( mid % 2 == 1){
                mid--;
            }
            if(nums[mid] != nums[mid+1]){
                right = mid;
            }
            else {
                left = mid + 2;
            }
        }
        return nums[left];
}
}