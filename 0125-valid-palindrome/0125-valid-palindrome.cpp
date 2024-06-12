class Solution {
public:
    string convertString(string s) {
        string word = "";
        for(char c : s) {
            if (isalpha(c) || isdigit(c))
                word += tolower(c);
        }
        return word;
    }
    bool isPalindrome(string s) {
        string word = convertString(s);
        
        int left = 0, right = word.size() - 1;
        while (left <= right) {
            if(word[left] != word[right])
                return false;
            ++left, -- right;
        }
        
        return true;
    }
};