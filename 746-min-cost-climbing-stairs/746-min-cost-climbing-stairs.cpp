class Solution {
public:
    int minCost(vector<int>&cost, int i, vector<int>&dp){
        if(i >= cost.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = cost[i] + min(minCost(cost,i+1,dp), minCost(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        
        return min(minCost(cost,0,dp), minCost(cost,1,dp));
    }
};