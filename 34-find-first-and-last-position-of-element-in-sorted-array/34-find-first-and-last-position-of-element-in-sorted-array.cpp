class Solution {
public:
    vector<int>expand(vector<int>& nums,int left,int right){
        int element = nums[left];
        --left;++right;
        while(left >= 0 && nums[left] == element)
            --left;
        while(right < nums.size() && nums[right] == element)
            ++right;
        vector<int>ans;
        ans.push_back(left + 1);
        ans.push_back(right - 1);
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        vector<int>ans;
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target){
                ans = expand(nums,mid,mid);
                return ans;
            }
            if(target < nums[mid])
                right = mid - 1;
            else left = mid + 1;
        }
        
        return {-1,-1};
    }
};