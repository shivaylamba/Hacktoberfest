#include<bits/stdc++.h>
using namespace std;

//maximise profit by buying and selling stocks

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for (int i=0;i<n;i++){
            int cost = prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
            
        }
        
        return profit;
    }
};

int main()
{
    Solution obj;
    vector<int> prices = {2, 4, 5, 3, 6, 4};
    cout << obj.maxProfit(prices) << endl;

    return 0;
}