class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        int size = order.size();
        for(char c : order) mp[c] = size--;
        vector<pair<char, int>> prio;
        for(int i=0;i<s.length();++i) {
            if(mp.find(s[i]) == mp.end())
                prio.push_back({s[i], 0});
            else
                prio.push_back({s[i], mp[s[i]]});
        }
        
        sort(prio.begin(), prio.end(), [](const pair<char,int>&a, const pair<char,int>&b){
           return a.second > b.second; 
        });
        
        string ans;
        for(auto it : prio) {
            ans.push_back(it.first);
        }
        
        return ans;
         
    }
};