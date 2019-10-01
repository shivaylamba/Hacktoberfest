package com.codingblocks;

import java.util.Arrays;
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

    // Merge Sort
    public static void mergeSort(int[] arr, int l, int h){
        if (l == h)
            return;
        int m = (l + h) / 2;
        mergeSort(arr, l, m );
        mergeSort(arr, m+1, h);
        merge(arr, l, m, h);
    }

    public static void merge(int[] arr, int l, int m, int h){
        int[] res = new int[h-l+1];
        int i=0, j=0, k = 0;
        for (i = l, j = m+1; i <= m && j <= h; ) {
            if(arr[i] < arr[j])
                res[k++] = arr[i++];
            else
                res[k++] = arr[j++];
        }
        while ( j<= h)
            res[k++] = arr[j++];
        while ( i<= m)
            res[k++] = arr[i++];

        for (int n = 0; n< res.length; n++) 
            arr[n+l] = res[n];
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
        
        mergeSort(data, 0, data.length-1);
        System.out.println("Merge sort: ");
        System.out.println(Arrays.toString(data));

        reverse(data);
        System.out.print("Reversed: ");
        Utility.display(data);

        System.out.print("Inverse of {1,4,0,3,2,5} : ");
        int[] data2 = {1,4,0,3,2,5};
        Utility.display(inverse(data2));

    }
}



