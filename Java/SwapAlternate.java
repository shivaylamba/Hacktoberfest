public class SwapAlternate {
    
    public static void swapAlternate(int arr[]) {
        int n = arr.length;
    	
        for(int i=0;i<n-1;i+=2){
           int temp = arr[i];
           arr[i] = arr[i+1];
           arr[i+1] = temp; 
        }
    }
    
    public static void printArray(int[] arr) {
        for (int element : arr) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int arr[] = {5, 6, 7, 8,9};
        swapAlternate(arr);
        printArray(arr); //outputs {6,5,8,7,9}   
    }    
}
