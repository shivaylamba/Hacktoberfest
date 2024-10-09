import java.util.Scanner;

public class quickSort {

    public int partition(int[] arr, int l, int h) {
        int pivot = arr[l];
        int i = l + 1;
        int j = h;
        while (i <= j) {
            while (i <= h && arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap pivot element with arr[j]
        int temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;
        return j;
    }

    public void quick(int[] arr, int l, int h) {
        if (l < h) {
            int loc = partition(arr, l, h);
            quick(arr, l, loc - 1);
            quick(arr, loc + 1, h);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Elements after sorting:");
        quickSort sorter = new quickSort();
        sorter.quick(arr, 0, n - 1);
        for (int j = 0; j < n; j++) {
            System.out.println(arr[j]);
        }
        sc.close();
    }
}
