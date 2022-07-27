class comp{
public:
    bool operator()(pair<string,int>&a, pair<string,int>&b){
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp> maxHeap;
        
        unordered_map<string,int>mp;
        for(string word : words)mp[word]++;
        
        for(auto it : mp)
            maxHeap.push(it);
        
        vector<string>ans;
        while(k--){
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        
        return ans;
    }
};