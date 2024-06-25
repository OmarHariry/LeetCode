class Solution {
public:
    bool isValid(vector<int> nums, int threshold, int divisor) {
        int sum = 0;
        for(auto num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        int divisor = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isValid(nums, threshold, mid)) {
                divisor = mid;
                right = mid - 1;   
            }
            else
                left = mid + 1;
        }
        return divisor;
    }
};