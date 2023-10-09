public class FirstLastIndex {
    public static int[] searchRange(int[] nums, int target) {
        int start=-1,end=-1;
        int result[]=new int[2];
        for(int i=0;i<nums.length;i++){
            if(start==-1 && nums[i]==target)
            start=i;
            if(start!=-1 && nums[i]==target)
            end=i;
        }
        result[0]=start;
        result[1]=end;
        return result;
    }
    public static void main(String[] args) {
        int[] arr = { 1, 5, 6, 6, 6, 7, 9 };
        int[] answer = searchRange(arr, 6);
        System.out.println("First Index" + " " + answer[0]);
        System.out.println("Last Index" + " " + answer[1]);
    }
}