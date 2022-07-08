class Solution {
public:
    int longestValidParentheses(string s) {
        int left =0,right =0;
        int maxLen = 0;
    
        for(int i=0;i<s.length();++i){
            if(s[i] == '(')
                ++left;
            else
                ++right;
            
            if(left == right)
                maxLen = max(maxLen, left * 2);
            
            if(right > left)
                left = right = 0;
        }
        
        left = right = 0;
        for(int i = s.length() - 1;i>=0;--i){
            if(s[i] == ')')
                ++right;
            else ++left;
            
            if(right == left)
                maxLen = max(maxLen,2 * left);
            
            if(left > right)
                left = right = 0;
        }
        
        return maxLen;
        
    }
};