//function to find the number of times a sorted array is rotated

int pivotElementIndex(vector<int> arr){

    int n = arr.size();
    int start = 0;
    int end = n-1;
	    
    while(start <= end){
        if(arr[start] < arr[end]) return start;
        
        int mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]) return mid;
        
        if(arr[start] <= arr[mid]) start = mid+1;
        else if(arr[mid] <= arr[end]) end = mid-1;
    }
    return -1;
}

int countRotated(vector<int> arr){

    //to return the number of times an array is rotated we can simply return the index of the min. element or pivot element
    int pivotIndex = pivotElementIndex(arr);
    return pivotIndex; 
}