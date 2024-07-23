class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;        
        for(int num : nums) mp[num]++;
        vector<pair<int, int>>freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), [](const pair<int,int>&a, const pair<int,int>&b) {
            return a.second == b.second? a.first > b.first : a.second < b.second;
        });
        vector<int>ans;
        for(int i=0;i<freq.size();++i)
            ans.insert(ans.end(), freq[i].second, freq[i].first);
        
        return ans;

    }
};