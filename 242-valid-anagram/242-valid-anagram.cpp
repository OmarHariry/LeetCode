class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        vector<int>sFreq(26,0);
        vector<int>tFreq(26,0);
        
        for(int i=0;i<s.length();++i){
            sFreq[s[i]-'a']++;
            tFreq[t[i]-'a']++;
        }
        
        for(int i=0;i<26;++i){
            if(sFreq[i] != tFreq[i])
                return false;
        }
        
        return true;
        
    }
};