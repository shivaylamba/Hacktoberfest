package com.shashank;

import java.util.Scanner;

public class Inverse {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n = sc.nextInt();
        System.out.println("Enter array elements");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int[] inv = new int[arr.length];
        int[] temp = new int[arr.length];
        for (int i = 0; i < temp.length; i++) {
            temp[i] = i;
        }
        for (int i = 0; i < arr.length; i++) {
            int val = arr[i];
            if (search(temp, val)) {
                inv[val] = i;
            } else {
                System.out.println("Inverse not possible");
                return;
            }
        }
        System.out.println("Array inverse is ");
        for (int val : inv) {
            System.out.print(val + " ");
        }
        System.out.println();
    }

    private static Boolean search(int[] arr, int val) {

        for (int i1 : arr) {
            if (i1 == val) {
                return true;
            }
        }
        return false;
    }
}