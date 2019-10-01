
import java.util.Scanner;
import java.lang.*;

public class MergeSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of array to be sorted");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        mergeSort(arr, 0, arr.length-1);
        System.out.println("Sorted array is ");
        for (int val : arr) {
            System.out.println(val + " ");
        }

    }

    private static void mergeSort(int[] arr, int left, int right) {

        if (left < right) {
            int m = (left + right) / 2;
            mergeSort(arr, left, m);
            mergeSort(arr, m + 1, right);
            merge(arr, left, right, m);
        }
    }

    private static void merge(int[] arr, int left, int right, int m) {

        int n1 = m - left + 1;
        int n2 = right - m;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; ++i) {
            L[i] = arr[i + left];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = arr[m + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}