class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> vec;
        for(int i=0;i<names.size();++i)
            vec.push_back({names[i], heights[i]});
        
        sort(vec.begin(), vec.end(), [](const pair<string, int>&a, const pair<string, int> & b) {
            return a.second > b.second;        
        });
        vector<string>ans;
        for(auto p : vec)
            ans.push_back(p.first);
        
        return ans;
    }
};