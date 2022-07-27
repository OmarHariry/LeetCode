bool comp(pair<string,int>&a, pair<string,int>&b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>mp;
        
        for(int i=0;i<messages.size();++i){
            int count = 0;
            stringstream ss(messages[i]);
            string word;
            while(ss >> word){
                ++count;
            }
            mp[senders[i]] += count;
        }
        
        vector<pair<string,int>>arr;
        for(auto it : mp) arr.push_back(it);
        
        sort(arr.begin(),arr.end(),comp);
        
        return arr[0].first;
    }
};