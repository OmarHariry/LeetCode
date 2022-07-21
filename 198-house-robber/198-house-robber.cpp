class Solution {
public:
    int getMax(vector<int>&nums, int start, int end, vector<int>&dp){
        if(start == end)
            return nums[end];
        
        if(start > end)
            return 0;
        
        if(dp[start] != -1)
            return dp[start];
        
        int pick = nums[start] + getMax(nums, start+2, end, dp);
        int notPick = getMax(nums, start+1, end, dp);
        
        return dp[start] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        
        return getMax(nums,0,n-1,dp);
    }
};