//function to return the index of peak element from an unsorted array

int peakIndex(vector<int> arr){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end){

        int mid = start + (end-start)/2;

        if(mid > 0 || mid < n-1){
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
        }
        else if(mid == 0){
            if(arr[0] > arr[1]) return 0;
            else return 1;
        }
        else if(mid == n-1){
            if(arr[n-1] > arr[n-2]) return n-1;
            else return n-2;
        }

        if(arr[mid-1] > arr[mid]) end = mid-1;
        else start = mid+1;
    }
    return -1;
}