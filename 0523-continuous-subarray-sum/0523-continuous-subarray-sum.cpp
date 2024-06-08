class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixModK = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(int i=0;i<nums.size();++i) {
            prefixModK = ( prefixModK + nums[i] ) % k;
            if(mp.find(prefixModK) != mp.end()) {
                if (i - mp[prefixModK] > 1)
                    return true;
            } else
                mp[prefixModK] = i;
        }
        
        return false;
    }
};