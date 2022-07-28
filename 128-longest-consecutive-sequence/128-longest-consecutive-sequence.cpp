class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int currStreak = 0,longestStreak = 0;
        
        unordered_map<int,int>mp;
        
        for(int num : nums)mp[num]++;
        
        for(int i=0;i<nums.size();++i){
            
            if(mp.find(nums[i] - 1) == mp.end()){
                ++currStreak;
                int element = nums[i]+1;
                while(mp.find(element) != mp.end()){
                    ++element;
                    ++currStreak;
                }
                longestStreak = max(longestStreak, currStreak);
                currStreak = 0;
            }
            
        }
        
        return longestStreak;
        
    }
};