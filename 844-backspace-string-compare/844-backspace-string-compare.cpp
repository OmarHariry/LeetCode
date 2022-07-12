class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", t1 = "";

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '#') {
                if (i > 0 && !s1.empty())
                    s1.pop_back();
            }
            else
                s1 += s[i];
        }

        for (int i = 0; i < t.length(); ++i) {
            if (t[i] == '#') {
                if (i > 0 && !t1.empty())
                    t1.pop_back();
            }
            else
                t1 += t[i];
        }

        return s1 == t1;
        
    }
};