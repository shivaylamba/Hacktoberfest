class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int maxplatform = 1;
    int currentplatform = 1;
    int i = 1;
    int j = 0;
    // declaring the pointers to move in the arrival and the departure array
    
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            currentplatform++;
            i++;
        }
        else
        {
            currentplatform--;
            j++;
        }
        maxplatform = max(currentplatform,maxplatform);
    }
    return maxplatform;
    }
};