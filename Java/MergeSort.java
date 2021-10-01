public class MergeSort {  
    void merge(int array[], int low, int middle, int high) {  
        int s = middle - low + 1;  
        int e = high - middle;  
  
        int startArray[] = new int [s];  
        int endArray[] = new int [e];  
  
        for (int i=0; i<s; ++i)  
        startArray[i] = array[low + i];  
  
        for (int j=0; j<e; ++j)  
        endArray[j] = array[middle + 1+ j];  
        
        
        int i = 0, j = 0;  
        int k = low;  
        while (i<s&&j<e) {  
            if (startArray[i] <= endArray[j]) {  
                array[k] = startArray[i];  
                i++;  
            }  
            else {  
                array[k] = endArray[j];  
                j++;  
            }  
            k++;  
        }  
        while (i<s) {  
            array[k] = startArray[i];  
            i++;  
            k++;  
        }  
    
        while (j<e) {  
            array[k] = endArray[j];  
            j++;  
            k++;  
        }  
    }  
  
    void sort(int array[], int low, int high) {  
        if (low<high) {  
            int middle = (low+high)/2;  
            sort(array, low, middle);  
            sort(array , middle+1, high);  
            merge(array, low, middle, high);  
        }  
    }  
    public static void main(String args[]) {  
        int array[] = {52,86,43,67,94,108,252,52,16,23,7,3,33,50};  
        MergeSort sortArrayay = new MergeSort();  
        sortArrayay.sort(array, 0, array.length-1);  
        
        System.out.println("\nThe sorted array is:");  
        for(int i =0; i<array.length;i++) {  
            System.out.println(array[i]+"");  
        }  
    }  
} 