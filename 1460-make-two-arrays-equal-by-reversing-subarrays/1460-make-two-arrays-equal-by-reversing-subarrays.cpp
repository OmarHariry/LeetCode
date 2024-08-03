class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int x : arr) mp[x]++;
        
        for(int x : target) {
            if (mp[x] == 0)
                return false;
            mp[x]--;
        }
        return true;
    } 
};