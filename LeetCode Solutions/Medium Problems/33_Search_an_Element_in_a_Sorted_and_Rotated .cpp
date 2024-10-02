/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:
Input: nums = [1], target = 0
Output: -1
Constraints:
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

 // Method n0-1
 int BinarySearch(vector<int>& arr,int st,int en,int element){
    int mid =st + (en - st)/2; // optimized solution for large array
   while (st<=en){
    if(arr[mid] == element){
        return mid;
    }
    else if(arr[mid]<element){
        st = mid+1;
    }
    else{
        en = mid - 1 ;
    }
     mid =st + (en - st)/2;
   }
   return -1;
}
//  using the pivot function finding the minimum element
int getPivot(vector<int>& arr,int n){
    int s =0;
    int en = n-1;
    int mid = s + (en -s)/2;
    while(s<en){
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            en =mid ;
        }
        mid = s + (en -s)/2;
    }
    return s;
}
// after deciding the minimum element we applied binary search 
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = getPivot(arr,n);
    if(k>=arr[pivot] && k<= arr[n-1]){
          return BinarySearch(arr,pivot,n-1,k);
    }
    else{
                return BinarySearch(arr,0,pivot-1,k);
    }

}
// Method no-2
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[low]) {
                if (nums[mid] < target || target < nums[low]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (target < nums[mid] || target > nums[high]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};