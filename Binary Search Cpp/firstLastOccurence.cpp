//function to find the first and last occurence of an element in a sorted array

int firstOccurence(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    int firstOccur = -1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == num){
            for(int i=mid; i>=0; i--){
                if(arr[i] == num) firstOccur = i;
            }
            return firstOccur;
        }
        //another method for above if condition
        //even after finding the index at mid we will continue the search in the smaller half
        // if(arr[mid] == num){
        //     firstOccur = mid;
        //     end = mid-1;
        // }

        else if(num < arr[mid]) end = mid-1;
        else start = mid+1;
    }
    return firstOccur;
}

int lastOccurence(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    int lastOccur = -1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == num){
            for(int i=mid; i<n; i++){
                if(arr[i] == num) lastOccur = i;
            }
            return lastOccur;
        }
        //another method for above if condition
        //even after finding the index at mid we will continue the search in the greater half
        // if(arr[mid] == num){
        //     lastOccur = mid;
        //     start = mid+1;
        // }

        else if(num < arr[mid]) end = mid-1;
        else start = mid+1;
    }
    return lastOccur;
}