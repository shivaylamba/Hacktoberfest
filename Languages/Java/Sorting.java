package com.codingblocks;

import java.util.Scanner;

public class Sorting {

    // Bubble Sort
    public static void bubble(int[] nums){
        // run the loop n-1 times
        for (int i = 0; i < nums.length; i++) {

            // reduce items from last
            for (int j = 1; j < nums.length-i ; j++) {

                // swap if next item is smaller then previous
                if(nums[j] < nums[j-1])
                    Utility.swap(nums, j, j-1);
            }
        }
    }

    // Selection Sort
    public static void selection(int[] nums){
        for (int i = 0; i < nums.length; i++) {
            int last = nums.length-i-1;
            int max = Utility.max_limit(nums, 0, last);
            Utility.swap(nums, max, last);
        }
    }

    // Insertion sort
    public static void insertion(int[] nums){
        for (int i = 0; i < nums.length-1; i++) {
            for (int j = i + 1; j > 0 ; j--) {
                if(nums[j] < nums[j-1])
                    Utility.swap(nums, j-1, j);
                else
                    break;
            }
        }
    }
    // Reverse
    public static void reverse(int[] nums){

        for (int i = 0; i < nums.length/2 ; i++) {
            Utility.swap(nums, i, nums.length-i-1);
        }
    }

    // Inverse
    public static int[] inverse(int[] nums){

        int[] data = new int[nums.length];

        for (int p = 0; p < nums.length; p++) {
            int v = nums[p];
            data[v] = p;
        }
        return data;
    }


    public static void main(String[] args) {
        int[] data = {23, 45, 9, 18, 16};

        System.out.print("Original Array: ");
        Utility.display(data);

        System.out.print("Bubble Sorted: ");
        bubble(data);
        Utility.display(data);

        selection(data);
        System.out.print("Selection Sorted: ");
        Utility.display(data);

        insertion(data);
        System.out.print("Insertion sort: ");
        Utility.display(data);

        reverse(data);
        System.out.print("Reversed: ");
        Utility.display(data);

        System.out.print("Inverse of {1,4,0,3,2,5} : ");
        int[] data2 = {1,4,0,3,2,5};
        Utility.display(inverse(data2));

    }
}



