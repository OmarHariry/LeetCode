class Solution {
public:
    string sortSentence(string s) {
        vector<pair<string, int>> sen;
        stringstream ss(s);
        string token;
        while (ss >> token) {
            int prio = token.back();
            token.pop_back();
            sen.push_back({token, prio});
        }
        sort(sen.begin(), sen.end(), [](const pair<string,int>&a, const pair<string,int>&b){
            return a.second < b.second;
        });
        
        string ans;
        for(auto it : sen) {
            ans += it.first + " ";
        }
        ans.pop_back();
        return ans;
        
        
    }
};