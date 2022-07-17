
class Solution {
public:
    int calculateCost(vector<int>&cost,int i,vector<int>&dp){
        if(i >= cost.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = cost[i] + min(calculateCost(cost,i+1,dp), calculateCost(cost,i+2,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int>dp(cost.size()+1,-1);
        return min(calculateCost(cost,0,dp), calculateCost(cost,1,dp)); 
    }
};