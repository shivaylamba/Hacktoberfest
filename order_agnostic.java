public class order_agnostic {
    public static void main(String[] args) {
        int []arr={9,8,7,6,5,4,3,2,1};
        int target = 7;
        int start= 0;
        int end= arr.length-1;
        if(arr[start]<arr[end]){
            System.out.println(ascending(arr,target,start,end));
        }
        else
            System.out.println(descending(arr,target,start,end));
    }

    static int ascending(int[]arr,int target,int start ,int end){
        while(start<=end){
            int mid = start +(end-start)/2;
            if(target < arr[mid]){
                end= mid-1;
            }
            if(target > arr[mid]){
                start = mid+1;
            }
            if(target == arr[mid]){
                return mid;
            }
        }
        return -1;
    }
    static int descending(int []arr,int target,int start,int end){
        while(start<=end){
            int mid = start +(end-start)/2;
            if(target < arr[mid]){
                start = mid+1;
            }
            if(target > arr[mid]){
                end = mid-1;
            }
            if(target == arr[mid]){
                return mid;
            }
        }
        return -1;
    }
}