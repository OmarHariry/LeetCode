class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        
        for(int x : nums1) mp[x]++;
        
        vector<int> ans;
        for(int num : nums2) {
            if (mp.find(num) != mp.end() && mp[num] > 0) {
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};