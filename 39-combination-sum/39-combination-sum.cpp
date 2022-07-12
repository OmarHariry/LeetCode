class Solution {
public:
    void backtrack(vector<int>&candidates, vector<vector<int>>&ans,vector<int>&path,int i, int target){
        if(target == 0){
            ans.push_back(path);
            return;
        }
        
        if(target < 0 || i >= candidates.size())
            return;
        
        for(int k = i ;k<candidates.size();++k){
            path.push_back(candidates[k]);
            backtrack(candidates,ans,path,k,target - candidates[k]);
            path.pop_back();            
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        backtrack(candidates,ans,path,0,target);
        return ans;
    }
};