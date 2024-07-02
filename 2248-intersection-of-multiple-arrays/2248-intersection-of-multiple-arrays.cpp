class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(vector<int> arr : nums) {
            for(int num : arr) {
                mp[num]++;
            }
        }
         
        for(auto it : mp) {
            if(it.second == nums.size())
                ans.push_back(it.first);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};