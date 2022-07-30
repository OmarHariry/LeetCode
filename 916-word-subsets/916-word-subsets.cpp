class Solution {
public:
    vector<int> findFreq(string s){
        vector<int>freq(26,0);
        for(char c : s)freq[c-'a']++;
        return freq;
    }
    
    bool isMatch(vector<int>&s,vector<int>t){
        for(int i=0;i<26;++i){
            if(t[i] && t[i] > s[i])
                return false;
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>words2_freq(26,0);
        vector<int>maxFreq(26,0);
        
        for(string word : words2){
            words2_freq = findFreq(word);
            
            for(int i=0;i<26;++i){
                maxFreq[i] = max(maxFreq[i], words2_freq[i]);
            }
        }
        vector<string>ans;
        vector<int>words1_freq(26,0);
        for(string word : words1){
            words1_freq = findFreq(word);
            if(isMatch(words1_freq,maxFreq))
                ans.push_back(word);
        }
        
        return ans;
    }
};