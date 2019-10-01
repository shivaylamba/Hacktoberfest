package com.codingblocks;

public class Searching {

    // Linear search
    public static int linear(int[] nums, int item){
        for (int i = 0; i <nums.length ; i++) {
            if (nums[i] == item)
                return item;
        }
        return -1;
    }


    // Binary Search: Only for sorted data
    public static int binary(int[] nums, int item){
        int start = 0;
        int end = nums.length - 1;
        while(start <= end){
            int mid = (start + end) / 2 ;

            if(item == nums[mid])
                return mid;

            else if(item > nums[mid])
                start = mid + 1;

            else if(item < nums[mid])
                end = mid - 1;
        }
        return -1;
    }


    public static void main(String[] args) {
        int [] data = {12, 34, 56, 78, 79, 90};
        int found = binary(data, 78);
        System.out.println(found);
    }

}
