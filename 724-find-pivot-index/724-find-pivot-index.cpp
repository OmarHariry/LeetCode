class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0,currSum =0;
        for(int x : nums)leftSum += x;
        
        for(int i=0;i<nums.size();++i){
            leftSum -= nums[i];
            if(leftSum == currSum)
                return i;
            
            
            currSum += nums[i];
        }
        return -1;
    }
};