import java.util.*;
import java.util.Map.Entry;
public class boore_voting {
    static int search_1(int arr[]) {
        int i, j;
        int temp = arr[0];
        int count = 0;
        for (i = 0; i < arr.length; i++) {
            for (j = 0; j < arr.length; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            if (count > arr.length / 2) {
                temp = arr[i];
            }
        }
        return temp;
    }

    static int search_2(int arr[]) {
        int count = 1;
        int l;
        int temp = arr[0];
        for (l = 1; l < arr.length; l++) {
            if (arr[l] == temp) {
                count++;
            } else {
                count--;
            }
            if (count <= 0) {
                temp = arr[l];
                count = 0;
            }
        }
        return temp;
    }    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k;
        int n;
        System.out.println("Enter the value of n");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the value of array");
        for (k = 0; k < arr.length; k++) {
            arr[k] = sc.nextInt();
        }
        System.out.println(search_1(arr));
        System.out.println(search_2(arr));        
    }
}
