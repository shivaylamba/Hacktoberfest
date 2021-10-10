public class BinarySearch {
    static int binarySearch(int arr[], int l, int h,int item){
        if(h >= l){
            int mid = (h+l)/2;
            if (item==arr[mid]){
                return mid;
            }
            if (item>arr[mid])
                return binarySearch(arr,mid+1,h,item);
            else
                return binarySearch(arr,l,mid-1,item);
        }
        return -1;
    }

}
