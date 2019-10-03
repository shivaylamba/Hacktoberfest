
import java.util.Scanner;
import java.lang.*;

public class QuickSort {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter " + i + " element");
            arr[i] = sc.nextInt();
        }
        int m = arr.length;
        quickSort(arr, 0, m - 1);

        for (int i1 : arr) {
            System.out.print(i1 + " ");
        }

    }

    private static void quickSort(int[] arr, int s, int e) {

        if (s < e && arr != null && arr.length > 1 && s >= 0 && e < arr.length) {
            int p = partition(arr, s, e);
            quickSort(arr, s, p - 1);
            quickSort(arr, p + 1, e);
        }

    }

    private static int partition(int[] arr, int s, int e) {

        int i = s - 1;
        int pivot = arr[e];
        for (int j = s; j < e; j++) {

            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[e];
        arr[e] = temp;
        return i + 1;
    }
}