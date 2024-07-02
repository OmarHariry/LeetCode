class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        unordered_set<int> intersection;
        vector<vector<int>>ans;
        unordered_set<int> s1;
        unordered_set<int> s2;
        
        for(int num : nums1) mp[num]++;
        for(int num : nums2) {
            if(mp.find(num) != mp.end() && mp[num] > 0) 
                intersection.insert(num);
        }
        
        vector<int> distinct;
        for(int num : nums1) {
            if (!intersection.count(num))
                s1.insert(num);
        }
        
        for(int num : nums2) {
            if(!intersection.count(num))
                s2.insert(num);
        }
        
        for(auto it : s1) {
            distinct.push_back(it);
        }
        ans.push_back(distinct);
        distinct.clear();
        for(auto it : s2) {
            distinct.push_back(it);
        }
        ans.push_back(distinct);
        return ans;
    }
};