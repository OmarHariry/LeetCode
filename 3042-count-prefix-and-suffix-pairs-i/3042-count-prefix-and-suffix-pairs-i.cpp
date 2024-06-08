class Solution {
public:
    bool isSuffixAndPrefix(string st1, string st2) {
        if (st1.length() > st2.length())
            return false;
        int i = 0;
        while(i < st1.length()) {
            if(st1[i] != st2[i])
                return false;
            ++i;
        }
        int j = st2.length()-1;
        i = st1.length() - 1;
        while (i >= 0) {
            if(st1[i] != st2[j]) 
                return false;
            --i, --j;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0;i<words.size()-1;++i) {
            for(int j=i+1;j<words.size();++j) {
                if(isSuffixAndPrefix(words[i], words[j]))
                    ++ans;
            }
        }
        return ans;
    }
};