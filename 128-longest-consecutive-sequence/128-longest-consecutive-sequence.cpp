class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x : nums)mp[x]++;
        
        int currStreak = 0,maxStreak = 0;
        for(int i=0;i<nums.size();++i){
            if(mp.find(nums[i] - 1) == mp.end()){
                ++currStreak;
                
                while(mp.find(nums[i] + 1) != mp.end()){
                    ++currStreak;
                    nums[i]++;
                }
                
            }
            maxStreak = max(maxStreak,currStreak);
            currStreak = 0;
            
        }
        
        return maxStreak;
    }
};