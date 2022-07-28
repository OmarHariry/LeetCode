class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        
        for(string word : strs){
            string original = word;
            sort(word.begin(),word.end());
            if(mp.find(word) != mp.end()){
                mp[word].push_back(original);
            }else{
                mp.insert({word,{original}});
            }
        }
        
        vector<vector<string>>ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};