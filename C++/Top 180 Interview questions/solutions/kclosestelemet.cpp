class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        vector<int> res;
        int high = arr.size() - k;
        
        while (low < high){
            int mid = low + (high-low)/2;
            if (x<=arr[mid]) 
                high=mid;
            else if (arr[mid+k]<=x)
                low = mid+1;
            else{
                int middist = abs(x-arr[mid]);
                
                int midkdist = abs(x-arr[mid+k]);
                
                if(middist <= midkdist)
                    
                    high=mid;
                    
                else
                    
                    low=mid+1;
            }
        }
        for(int i = low ; i < low + k ; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
    // high will be mid and low will be mid+1;
};