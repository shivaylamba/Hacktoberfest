import java.util.Arrays;

class BubbleSort{
  public static void bubbleSort(int[] arr){
    int n = arr.length;
  //bubble sort logic
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  }
  public static void main(String[] args){
    int[] arr ={4, 3, 6, 8, 2, 1};
    bubbleSort(arr);
    //printing sorted array
    System.out.println("Array after sorting: " + Arrays.toString(arr));
  }
}
