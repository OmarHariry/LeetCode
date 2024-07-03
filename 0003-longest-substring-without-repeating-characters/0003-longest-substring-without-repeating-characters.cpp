class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        
        int i=0, j = 0, ans = 0;
        while(j<s.length()) {
            if (set.find(s[j]) == set.end())
                set.insert(s[j++]);
            else
                set.erase(s[i++]);
            ans = max(ans, (int)set.size());
        }
        return ans;
    }
};