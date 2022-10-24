import java.util.Scanner;

class BinarySearch {
    private static int binarySearchRecursive(int[] a, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        int mid = (start + end)/2;

        if(target == a[mid]) {
            return mid;
        } else if (target < a[mid]) {
            return binarySearchRecursive(a, start, mid-1, target);
        } else {
            return binarySearchRecursive(a, mid+1, end, target);
        }
    }

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        int n = keyboard.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
          a[i] = keyboard.nextInt(); 
        }
        int target = keyboard.nextInt();
        keyboard.close();

        System.out.printf("BinarySearch(%d) = %d%n", target, binarySearchRecursive(a, 0, n-1, target));
    }
}
