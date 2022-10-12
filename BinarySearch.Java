import java.util.*;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        int target = input.nextInt();

        for (int i=0; i<n; i++){
            arr[i]=input.nextInt();
        }

        binarySearch(arr,target);

    }

    static void binarySearch(int[] arr, int target){
        int l = 0;
        int h = arr.length-1;

        while (l<h){
            int mid = l+(h-l)/2;
            if(arr[mid]==target){
                System.out.println(mid);
            }
            else if (arr[mid]>target){
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
    }
}