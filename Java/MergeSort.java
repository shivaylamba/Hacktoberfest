public class MergeSort {
 void sort(int arr[],int l,int r){
        if(l<r)
        {
        int m = (l+r)/2;

        sort(arr,l,m);
        sort(arr,m+1,r);

        merge(arr,l,m,r);
        }
    }


    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    static void merge(int arr[],int l, int m, int r){
       int n1 = m-l+1;//size of array1
       int n2 = r-m;//size of array2

        int L[] = new int[n1];
        int R[] = new int[n2];

        for (int i=0;i<n1;++i){
            L[i] = arr[l+i];
        }
        for (int i=0;i<n2;++i){
            R[i] = arr[m+1+i];
        }

        /* Merge the temp arrays */
        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy remaining elements of L[] if any */
        while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy remaining elements of R[] if any */
        while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


    }
    void printArray(int arr[]){
        int a =0;
        for(int i = 0;i<arr.length;i++){
            System.out.print(arr[i]+" ");;
        }
    }
    public static void main(String[] args) {
        int arr[] = {12,11,13,15,6,7};
        MergeSort ms = new MergeSort();
        System.out.println("Given Array : ");
        ms.printArray(arr);

        ms.sort(arr,0,arr.length-1);

        System.out.println("\nSorted array: ");
        ms.printArray(arr);

    }

}
