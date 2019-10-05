import java.util.*;

public class Sorting {
    // Bubble Sort
    public static void BubbleSort (int[] arr) {
        int length = arr.length;
        for (int i = 0; i < length - 1; i++)
            for (int j = 0; j < length - i - 1; j++)
                if (arr[j] > arr [j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }

    // Insertion Sort
    public static void InsertionSort (int[] arr) {
        int length = arr.length;
        for ( int i = 1; i < length; i++){
            int j = i-1;
            int key = arr[i];
            while( j >= 0 && arr[j] > key )
                arr[j+1] = arr[j--];
            arr[j+1] = key;
        }
    }

    // Selection Sort
    public static void SelectionSort (int[] arr) {
        int length = arr.length;
        for ( int i = 0; i < length; i++){
            int min = i;
            int temp = arr[i];
            for (int j = i+1; j < length; j++)
                if(arr[j] < arr[min])
                    min = j;
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    // Merge Sort
    public static void merge(int[] arr, int low, int mid, int high){
        int[] res = new int[high-low+1];
        int i=0, j = 0, k = 0;
        for (i = low, j = mid +1; i <= mid && j <= high;){
            if(arr[i] < arr[j])
                res[k++] = arr[i++];
            else
                res[k++] = arr[j++];
        }

        while ( i<= mid )
            res[k++] = arr[i++];
        while ( j<= high )
            res[k++] = arr[j++];

        for (int n = 0; n < high-low+1; n++)
            arr[n+low] = res[n];

    }

    public static void MergeSort (int[] arr, int low, int high) {
        if (low == high)
            return;
        int mid = (low + high)/2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

    // Quick Sort
    public static int partition (int[] arr, int low, int high) {
        int piv = arr[high], i, j, temp;
        for (i = low - 1, j = low; j < high; j++ )
            if(arr[j] < piv){
                temp = arr[++i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        temp = arr[++i];
        arr[i] = arr[j];
        arr[j] = temp;
        return i;
    }

    public static void QuickSort(int[] arr, int low, int high){
        if( low <= high ){
            int piv = partition(arr, low, high);
            QuickSort(arr, low, piv-1);
            QuickSort(arr, piv+1, high);
        }
    }
    
    // RandomQuick Sort
    public static void RandomQuickSort (int[] arr, int low, int high) {
        Random rObj = new Random();
        int rand = rObj.nextInt(high - low) + low;
        int temp = arr[high];
        arr[high] = arr[rand];
        arr[rand] = temp;

        if( low <= high ){
            int piv = partition(arr, low, high);
            QuickSort(arr, low, piv-1);
            QuickSort(arr, piv+1, high);
        }
    }

    // Dual Pivot Quick Sort
    public static void DualPivotQuickSort (int[] arr, int low, int high) {
        // Help Required
    }

    // Counting Sort
    public static void CountingSort (int[] arr) {
        
    }

    // Radix Sort
    public static void RadixSort (int[] arr) {
        
    }

    // Bucket Sort
    public static void BucketSort (int[] arr) {
        
    }
    
    // Heap Sort
    public static void HeapSort (int[] arr) {
        
    }


    public static void main(String args[]) {
        int[] data = {23, 31, 21, 12, 24, 9, 4, 81, 19};
        
        // BubbleSort(data);
        // System.out.println(Arrays.toString(data));
        
        // InsertionSort(data);
        // System.out.println(Arrays.toString(data));

        // SelectionSort(data);
        // System.out.println(Arrays.toString(data));

        // MergeSort(data, 0, data.length-1);
        // System.out.println(Arrays.toString(data));

        // QuickSort(data, 0, data.length-1);
        // System.out.println(Arrays.toString(data));
        
        DualPivotQuickSort(data, 0, data.length-1);
        System.out.println(Arrays.toString(data));
    }
}