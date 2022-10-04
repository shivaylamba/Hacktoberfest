//function to find an element in a rotated sorted array

//function to find the index of minimum element
int findPivot(vector<int> arr){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end){
        
        if(arr[start] < arr[end]) return start;

        int mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;

        if(arr[mid] < arr[prev] && arr[mid] < arr[next]) return mid;

        if(arr[start] <= arr[mid]) start = mid+1;
        else if(arr[mid] <= arr[end]) end = mid-1;
    }
    return -1;
}

//basic binary search function
int findIndex(vector<int> arr, int start, int end, int num){

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == num) return mid;

        if(num > arr[mid]) start = mid+1;
        else end = mid-1;
    }

    return -1;
}

//find the index of minimum element and then search for the element on the both sides of min. index
int findElementRotated(vector<int> arr, int num){

    int n = arr.size();
    int pivotIndex = findPivot(arr);

    int index1 = findIndex(arr, 0, pivotIndex-1, num);
    int index2 = findIndex(arr, pivotIndex+1, n-1, num);

    if(index1 == -1 && index2 == -1) return -1;
    else{
        if(index1 == -1) return index2;
        else return index1;
    }
}