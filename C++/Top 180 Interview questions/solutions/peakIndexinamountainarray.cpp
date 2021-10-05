class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // return the bitonic point
        int low = 0;
        int n = arr.size();
        int high = n - 1;
        while(low<high)
        {
            int mid = (low + high) >> 1;
            if(arr[mid] >= arr[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};