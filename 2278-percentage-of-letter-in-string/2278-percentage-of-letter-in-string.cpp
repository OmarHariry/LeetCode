class Solution {
public:
    int percentageLetter(string s, char letter) {
        int freq = 0;
        for(char c : s) { 
            if (c == letter) 
                ++freq; 
        }
        return freq * 100 / s.size() ;
    }
};