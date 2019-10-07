package com.codewars;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;


/**
 * Kata "Next smaller number with the same digits" solution
 * https://www.codewars.com/kata/next-smaller-number-with-the-same-digits/java
 *
 * Write a function that takes a positive integer and returns the next smaller positive integer containing the
 * same digits.
 *
 * For example:
 *
 *    nextSmaller(21) == 12
 *    nextSmaller(531) == 513
 *    nextSmaller(2071) == 2017
 *
 * Return -1 , when there is no smaller number that contains the same digits. Also return -1 when the next smaller
 * number with the same digits would require the leading digit to be zero.
 *
 *    nextSmaller(9) == -1
 *    nextSmaller(111) == -1
 *    nextSmaller(135) == -1
 *    nextSmaller(1027) == -1 // 0721 is out since we don't write numbers with leading zeros
 *
 * - some tests will include very large numbers.
 * - test data only employs positive integers.
 */
public class NextSmallerWithSameDigits {

    public static long nextSmaller(long n)
    {
        String strNumber = String.valueOf(n);
        char[] ar = String.valueOf(n).toCharArray();
        int smallerPosition = 0;
        for (int i = 1; i < strNumber.length(); i++)
        {
            if (ar[i-1] > ar[i]) {
                smallerPosition = i;
            }
        }

        long result;
        if (smallerPosition == 0)
        {
            return -1;
        }
        else
        {
            int x = ar[smallerPosition-1];
            int rightSwapPosition = 0;

            for (int j = smallerPosition+1; j < ar.length; j++)
            {
                if (ar[j] < x)
                {
                    rightSwapPosition = j;
                }
            }

            if (rightSwapPosition == 0) {
                swap(ar, smallerPosition, smallerPosition - 1);
            }
            else {
                swap(ar, smallerPosition-1, rightSwapPosition);
            }



            SortDesc(ar, smallerPosition, strNumber.length()-1);
            if (ar[0] == '0') {
                return -1;
            }
            result = Long.parseLong(String.valueOf(ar));
        }
        return result;
    }

    static void swap(char ar[], int i, int j)
    {
        char temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }

    static void SortDesc(char arr[], int i, int j) {
        for (int k = i; k <= arr.length -1; k++) {
            int maxIndex = k;
            for (int l = k; l <= arr.length-1; l++) {
                if (arr[l] > arr[maxIndex]) {
                    maxIndex = l;
                }
            }
            swap(arr, k, maxIndex);
        }
    }

}
