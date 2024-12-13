class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        unordered_map<int, int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        for(int i=0;i<nums.size();++i) {
            mp[i]=0;
            minHeap.push({nums[i], i});
        }
        
        while(!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            
            if(mp[top.second] == 0) {
                mp[top.second] = 1;
                score += top.first;
                if (top.second - 1 >= 0)
                    mp[top.second-1] = 1;
                if(top.second + 1 < nums.size())
                    mp[top.second+1] = 1;
            }
        }
        return score;
    }
};