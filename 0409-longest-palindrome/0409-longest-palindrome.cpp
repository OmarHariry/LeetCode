class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c : s)mp[c]++;
        
        bool flag = false;
        int ans = 0;
        for(auto it : mp){
            if(it.second % 2 == 0){
                ans += it.second;
            }
            else{
                flag = true;
                ans += it.second - 1;
            }
        }
        
        return flag == true ? ans + 1 : ans; 
        }
};