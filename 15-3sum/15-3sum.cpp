class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<vector<int>, int>mp;
        
        
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();++i){
            int j = i+1,k= nums.size()-1;
            
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int>triplet({nums[i],nums[j],nums[k]});
                    if(mp.find(triplet) == mp.end()){
                        mp[triplet]++;
                        ans.push_back(triplet);
                        
                    }
                    ++j;--k;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                    ++j;
                else
                    --k;
            }
            
        }
        return ans;
    }
};