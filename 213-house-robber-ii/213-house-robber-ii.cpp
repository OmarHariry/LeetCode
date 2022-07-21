class Solution {
public:
    int getMax(vector<int>&nums, int start, int end, vector<int>&dp){
        if(start == end)
            return nums[start];
        
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
        if(n == 1)
            return nums[0];
        
        vector<int>dp(n,-1);
        int first = getMax(nums,0,n-2, dp);
        
        vector<int>dp2(n,-1);
        int second = getMax(nums,1,n-1,dp2);
        
        return max(first,second);
        
    }
};