
import java.util.Arrays;

class SelectionSort {
    public static void main(String[] args) {
        int[] arr = { 11, 2, 66, 77, 30 };
        int n = arr.length;
        SelSort(arr, n);
        System.out.println(Arrays.toString(arr));
    }

    private static void SelSort(int[] arr, int n) {
        int min, temp;
        for (int k = 0; k < n - 1; k++) {
            min = k;

            for (int j = k + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;

                }

            }
            if (min != k) {
                temp = arr[k];
                arr[k] = arr[min];
                arr[min] = temp;
            }
        }
    }

}