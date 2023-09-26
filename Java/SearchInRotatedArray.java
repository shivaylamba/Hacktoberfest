class SearchInRotatedArray {
    public int search(int[] nums, int target) {

    //     I. Naive Approach | O(n)
    //     for(int i= 0; i< nums.length; i++){
    //         if(nums[i] == target){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // II. Binary Search Appraoch
    int left = 0, right = nums.length -1;
    while(left <= right){
        int mid = (left + right) /2;
        if( nums[mid] == target){
            return mid;
        }
        // is left array sorted?
        if( nums[left] <= nums[mid]){
            if(nums[left] <= target && nums[mid] >= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        // no, therefore right array is sorted
        else {
            if(nums[mid] <= target && nums[right] >= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;
}
}