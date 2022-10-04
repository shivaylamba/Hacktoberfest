//function to apply binary search where the order of given sorted array is not known

int orderAgnosticSearch(vector<int> arr, int num){
    
    int n = arr.size();
    int start = 0;
    int end = n-1;

    bool isAscending;
    if(arr[0] < arr[1]) isAscending = true;
    else isAscending = false;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(num == arr[mid]) return mid;
        else if(num < arr[mid]){
            if(isAscending) end = mid-1;
            else start = mid+1;
        }
        else{
            if(isAscending) start = mid+1;
            else end = mid-1;
        }
    }
    return -1;
}