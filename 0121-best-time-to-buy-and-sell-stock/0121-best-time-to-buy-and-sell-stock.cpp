class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // O(n) time, constant space
        // buy  and if the next day is cheaper buy on that day
        // calculate the profit and maxProfit accordingly
        
        int buy = INT_MAX, profit = 0, maxProfit = 0;
        for(int i=0;i<prices.size();++i) {
            buy = min(buy, prices[i]);
            profit = prices[i] - buy;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};