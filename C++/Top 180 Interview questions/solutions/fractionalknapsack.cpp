class Solution
{
    public:
    static bool comp(Item a, Item b)
    {
        double d1 = (double) a.value / (double) a.weight;
        double d2 = (double) b.value / (double) b.weight;
        if(d1 > d2) return true;
        else return false;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // first sort according to value / weight
        sort(arr, arr + n, comp);
        int curweight = 0;
        double curvalue = 0.0;
        for(int i = 0 ; i < n; i++)
        {
            if(curweight + arr[i].weight <= W)
            {
                curweight+=arr[i].weight;
                curvalue+=arr[i].value;
            }
            else
            {
             int remain = W - curweight;
             curvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
             break;
            }
        }
        return curvalue;
    }
        
};
