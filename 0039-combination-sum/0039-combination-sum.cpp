class Solution {
public:
    void dfs(vector<int>&candidates, int target, int sum, 
                           vector<vector<int>>&ans, vector<int>&path, int index) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        
        for(int i=index;i<candidates.size();++i) {
            if(sum + candidates[i] <= target) {
                path.push_back(candidates[i]);
                dfs(candidates, target, sum + candidates[i], ans, path, i);
                path.pop_back();
            } 
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(candidates, target, 0, ans, path, 0);
        return ans;
    }
};