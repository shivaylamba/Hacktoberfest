import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MergeSortedArrays {
    
    /*
    This program merges two sorted integer arrays into one sorted array.
    The time complexity for this algorithm is O(m + n) where m, n are the respective sizes of the two sorted integer arrays.
    The space complexity is O(m + n), considering the auxiliary space needed for storing the merged sorted array result.
    Please note that I did not add main(), it is left for the end-user.
    */
    
    public static List<Integer> mergeTwoSortedArray(List<Integer> v1, List<Integer> v2) {
        int m = v1.size(), n = v2.size();
        int i = 0, j = 0;
        List<Integer> result = new ArrayList<>();

        // Merge elements from both lists until one list is exhausted
        while (i < m && j < n) {
            if (v1.get(i) < v2.get(j)) {
                result.add(v1.get(i));
                i++;
            } else {
                result.add(v2.get(j));
                j++;
            }
        }

        // Add remaining elements from v1 if any
        while (i < m) {
            result.add(v1.get(i));
            i++;
        }

        // Add remaining elements from v2 if any
        while (j < n) {
            result.add(v2.get(j));
            j++;
        }

        return result;
    }

    public static void main(String[] args) {
        int n1, n2, x;
        Scanner sc = new Scanner(System.in);
        
        // creating first sorted list of integers
        System.out.println("Enter the size of first sorted array: ");
        n1 = sc.nextInt();
        List<Integer> v1 = new ArrayList<>(n1);
        
        System.out.println("Enter elements of first array in sorted order: ");
        for (int i = 0; i < n1; i++) {
            x = sc.nextInt();
            v1.add(x);
        }
        
        // creating second sorted list of integers
        System.out.println("\nEnter the size of second sorted array: ");
        n2 = sc.nextInt();
        List<Integer> v2 = new ArrayList<>(n2);
        
        System.out.println("Enter elements of second array in sorted order: ");
        for (int i = 0; i < n2; i++) {
            x = sc.nextInt();
            v2.add(x);
        }
        
        
        List<Integer> result = mergeTwoSortedArray(v1, v2);
        System.out.println("\nThe resultant sorted array: ");
        
        // Print the merged result
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
