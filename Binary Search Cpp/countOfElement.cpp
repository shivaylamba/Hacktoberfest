//function to count the occurence of an element in a sorted array;

int countOccurence(vector<int> arr, int num){

    int n = arr.size();
    int low = 0; 
    int high = n-1;

    int count = 0;
    int firstOccur = 0;
    int lastOccur = 0;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == num){
            firstOccur = mid;
            high = mid-1;
        }

        else if(arr[mid] > num) high = mid-1;
        else low = mid+1;
    }

    low = 0;
    high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == num){
            lastOccur = mid;
            low = mid+1;
        }

        else if(arr[mid] > num) high = mid-1;
        else low = mid+1;
    }

    count = lastOccur-firstOccur+1;
    return count;
}