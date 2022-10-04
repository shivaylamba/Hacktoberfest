//function to find the minimum difference element from a sorted array

int minDiffElement(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end){

        int mid = start + (end-start)/2;

        if(arr[mid] == num) return arr[mid];

        if(num < arr[mid]) end = mid-1;
        else start = mid+1;
    }

    int ans1 = abs(arr[start]-num);
    int ans2 = abs(arr[end]-num);

    if(ans1 < ans2) return arr[start];
    else return arr[end];
}