/**
 * BinarySearch
 */
public class BinarySearch {

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 5, 6};
        int target = 4;
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                System.out.println(mid);
                break;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
}