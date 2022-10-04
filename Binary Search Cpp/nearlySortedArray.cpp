//function to search an element in a nearly sorted array
//element at ith position can be present at -> ith, (i+1)th, (i-1)th position

int searchInNearlySorted(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end){

        int mid = start + (end-start)/2;

        if(arr[mid] == num) return mid;
        if(mid-1 >= start && arr[mid-1] == num) return mid-1;
        if(mid+1 <= end && arr[mid] == num) return mid+1;

        if(num > arr[mid]) start = mid+1;
        else end = mid-2;
    }
    return -1;
}