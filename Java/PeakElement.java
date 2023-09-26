//  162. Find Peak Element | Medium
//        A peak element is an element that is strictly greater than its neighbors.
//        Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
//        You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
//        You must write an algorithm that runs in O(log n) time.

//        Example 1:
//
//        Input: nums = [1,2,3,1]
//        Output: 2
//        Explanation: 3 is a peak element and your function should return the index number 2.

package binarysearch;

import java.util.Arrays;

public class PeakElement {
    public int findPeakElement(int[] nums) {

        // 1. Brute Approach
        // {1,2,3,1}
        // 1, 0 -> 2
        // 2, 1 -> 1,3
        // 3,2 -> 1,2,1 return 2 (index of 3)

//        for (int i = 0; i < nums.length; i++) {
//            int element = nums[i]; // 2
//            for (int j = 0; j < nums.length; j++) {
//                System.out.println("i "+i+" --"+ nums[i]);
//                System.out.println("   j "+j+" --"+ nums[j]);
//                if(j == i) continue;
//                else {
//                    if(nums[j] >= element) break;
//                    if(j == nums.length-1) return i;
//                }
//            }
//        }
//        return 0;

        // O(logn): Binary Search method
        int left = 0, right = nums.length -1;

        while (left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] > nums[mid-1] && nums[mid+1] < nums[mid]) return mid;
            else if (nums[mid-1] > nums[mid]) right = mid-1;
            else if(nums[mid +1] > nums[mid]) left = mid+1;

        }
        return 0;
    }
    public static void main(String[] args) {
        int[] nums = {1,2,1,3,5,6,4};
        PeakElement pe = new PeakElement();
        System.out.println( pe.findPeakElement(nums));
    }
}
