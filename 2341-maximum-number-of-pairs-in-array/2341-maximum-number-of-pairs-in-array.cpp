class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x : nums)mp[x]++;
        
        vector<int>ans(2,0);
        for(auto it : mp){
            if(it.second % 2 == 0)
                ans[0] += it.second / 2;
            else{
                ans[0] += (it.second - 1) / 2;
                ans[1] += 1;
            }
        }
        
        return ans;
    }
};