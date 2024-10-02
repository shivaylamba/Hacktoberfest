class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //         int max = 0;
        // int n = prices.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int profit = prices[j]-prices[i];
        //         if(max < profit){
        //             max = profit;
        //         }
        //     }
        // }
        // return max;

        int min_price = prices[0];
        int maxprof = 0;

        for(int i=1;i<prices.size();i++){
            maxprof = max(maxprof,prices[i]-min_price);
            min_price = min(prices[i],min_price);
        }

        return maxprof;
    }
};