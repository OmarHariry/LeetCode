class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        
        vector<pair<char, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), [](const pair<char,int>&a, const pair<char,int>&b){
           return a.second > b.second;
        });
        
        string ans;
        for(auto it : freq)
            ans.append(it.second, it.first);
        
        return ans;
        
    }
};