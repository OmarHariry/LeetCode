class Solution {
public:
    void backtrack(vector<int>&nums, vector<vector<int>>&ans, vector<int>&path, map<pair<int,int>,int>&mp){
        
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=0;i<nums.size();++i){
            if(mp.find({nums[i], i}) == mp.end()){
                path.push_back(nums[i]);
                mp[{nums[i], i}]++;
                backtrack(nums,ans,path,mp);
                path.pop_back();
                mp.erase({nums[i],i});
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>path;
        map<pair<int,int>,int>mp;
        backtrack(nums,ans,path,mp);
        set<vector<int>>mySet(ans.begin(),ans.end());
        vector<vector<int>>unique(mySet.begin(),mySet.end());
        return unique;
    }
};