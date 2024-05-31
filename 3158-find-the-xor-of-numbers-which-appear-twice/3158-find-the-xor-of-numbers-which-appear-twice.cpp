class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int num : nums)
            mp[num]++;
        int ans = 0;
        for(auto it : mp) {
            if (it.second == 2)
                ans ^= it.first;
        }
        return ans;
    }
};