class Solution 
{
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        // we need to find the number with maximum deadline
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }
        // now we create a array with -1
        
        int array[maxi + 1];
        memset(array, -1, sizeof(array));
        // just to be on a safer side
        int num = 0;
        int maxprofit = 0;
        // deadline cannot be 0 j > 0
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = arr[i].dead ; j>0 ; j--)
            {
                if(array[j]==-1){
                array[j] = i;
                num++;
                maxprofit+=arr[i].profit;
                break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(num);
        ans.push_back(maxprofit);
        return ans;
    } 
};