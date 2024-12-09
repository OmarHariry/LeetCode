class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>prefix(nums.size(), 0);
        vector<bool>ans(queries.size(), false);
        for(int i=1;i<nums.size();++i) {
            if (nums[i] % 2 == nums[i-1] % 2) 
                prefix[i] = prefix[i-1] + 1;
            else
                prefix[i] = prefix[i-1];
        }
        for(int i=0;i< queries.size();++i) {
            auto query = queries[i];
            int start = query[0], end = query[1];
            ans[i] = prefix[end] - prefix[start] == 0;
        }
        return ans;
    }
};