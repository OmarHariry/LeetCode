class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, prefixModK = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        
        for(int i=0;i<nums.size();++i) {
            prefixModK = (prefixModK + nums[i] % k + k) % k;
            
            if (mp.find(prefixModK) != mp.end()) {
                ans += mp[prefixModK];
                mp[prefixModK]++;
            } else
                mp[prefixModK] = 1;

        }
        
        return ans;
    }
};