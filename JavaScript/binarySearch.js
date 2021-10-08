function binarySearch(nums, target) {
    let start = 0
    let end = nums.length
    let middle = parseInt((start + end) / 2)

    for(let i = 0; i<=nums.length; i++){
        if(nums[middle] != target){
            if(target < nums[middle]){
                end = middle
            }else{
                start = middle
            }
            middle = parseInt((start + end) / 2)
        }else{
            return middle
        }
    }
    
    return -1
};