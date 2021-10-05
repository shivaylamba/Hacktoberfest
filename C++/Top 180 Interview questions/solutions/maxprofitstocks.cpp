class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minElement = INT_MAX;
        for(int i = 0 ; i < prices.size(); i++)
        {
            minElement = min(prices[i],minElement);
            maxprofit = max(maxprofit, prices[i] - minElement);
        }
        return maxprofit;
    }
};