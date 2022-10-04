//function to allocate minimum number of pages

bool isValid(vector<int> arr, int k, int num){

    int n = arr.size();

    int students = 1;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum > num){
            students++;
            sum = arr[i];
        }
        if(students > k) return false;
    }
    return true;
}

int maxPagesAllocated(vector<int> arr, int k){

    int n = arr.size();
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;
    while(start <= end){

        int mid = start + (end-start)/2;

        if(isValid(arr, k, mid)){
            ans = mid;
            end = mid-1;
        }

        else start = mid+1;
    }
    return ans;
}