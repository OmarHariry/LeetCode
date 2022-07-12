class Solution {
public:
    void backtrack(vector<int>&nums, vector<int>&path, vector<vector<int>>&ans,unordered_map<int,int>&mp){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        
        for(int k = 0;k<nums.size();++k){
            if(mp.find(nums[k]) == mp.end()){
                path.push_back(nums[k]);
                mp[nums[k]]++;
                backtrack(nums,path,ans,mp);
                path.pop_back();
                mp.erase(nums[k]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        backtrack(nums, path, ans,mp);
        return ans;
    }
};