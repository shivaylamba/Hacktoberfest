public class BinarySearch {
    public static void main(String[] args) {
        System.out.println("Binary Search....!!!!!!");
        int[] arr = {1,2,3,4,5,7,8,9,13,14,16,19,21,24,26,28,29,35,37,45,68,78,89,90,100};
        System.out.println(BS(arr,16));
    }
    static int BS(int[] arr,int target){
        int start = 0;
        int end = arr.length -1;
        while(start <= end){
            int mid = start + (end -start) / 2;
            if(arr[mid] < target){
                start = mid + 1;
            }
            else if(arr[mid] > target){
                end = mid - 1;
            }
            else {
                return mid;
            }
        }
        return start;
    }
}
