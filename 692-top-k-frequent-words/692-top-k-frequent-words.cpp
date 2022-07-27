bool comp(pair<string,int>&a,pair<string,int>&b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        
        for(string word : words)mp[word]++;
        
        vector<pair<string,int>>arr;
        for(auto it : mp)
            arr.push_back({it.first,it.second});
        
        sort(arr.begin(),arr.end(),comp);
        
        vector<string>ans;
        for(int i=0;i<k;++i){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};