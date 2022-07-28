class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int>ans;
        
        while(left < right){
            if(nums[left] + nums[right] == target){
                ans.push_back(left+1);ans.push_back(right+1);
                return ans;}
            if(nums[left] + nums[right] < target)
                ++left;
            else
                --right;
        }
        return ans;
    }
};