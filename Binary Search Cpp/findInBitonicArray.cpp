//function to find an element in a Bitonic array

int binarySearch(vector<int> arr, int num, int start, int end, int size){

    if(arr[start] < arr[start+1]){
        while(start <= end){

            int mid = start + (end-start)/2;

            if(arr[mid] == num) return mid;
            
            if(num > arr[mid]) start = mid+1;
            else end = mid-1;
        }
    }
    else if(arr[start] > arr[start+1]){
        while(start <= end){

            int mid = start + (end-start)/2;

            if(arr[mid] == num) return mid;

            if(num > arr[mid]) end = mid-1;
            else start = mid+1;
        }
    }
    return -1;
}

int peakIndexBitonicArray(vector<int> arr){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end){

        int mid = start + (end-start)/2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
        else if(mid == 0){
            if(arr[0] > arr[1]) return 0;
            else return 1;
        }
        else if(mid == n-1){
            if(arr[n-1] > arr[n-2]) return n-1;
            else return n-1;
        }

        if(arr[mid-1] > arr[mid]) end = mid-1;
        else start = mid+1;
    }

    return -1;
}

//first find the peak element and divide the given array in two halves and search for the respective element in those halves
int findElementBitonicArray(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    int peakIndex = peakIndexBitonicArray(arr);

    int ans1 = binarySearch(arr, num, start, peakIndex-1, peakIndex);
    int ans2 = binarySearch(arr, num, peakIndex, n-1, n-peakIndex);

    if(ans1 != -1) return ans1;
    else return ans2;
}