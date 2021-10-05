class Solution
{
public:
    void func(int index, int sum,vector<int>& arr, int n , vector<int>& result)
    {
        if(index == n)
        {
            result.push_back(sum);
            return;
        }
        // first we include the element at that index
        func(index + 1 , sum+arr[index],arr, n , result);
        
        // we don't include that index
        func(index+1, sum,arr,n , result);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // very basic recursion
        vector<int> result;
        func(0,0,arr,n,result);
        sort(result.begin(), result.end());
        return result;
    }
};