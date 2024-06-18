class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> work;
        for(int i=0;i<difficulty.size();++i)
            work.push_back({difficulty[i], profit[i]});
        
        sort(work.begin(), work.end(), [](const pair<int,int>& a, const pair<int,int>&b){
            return a.second > b.second;
        });
        sort(worker.begin(), worker.end(), greater<int>());
        
        int i = 0, j = 0;
        int ans = 0;
        while (i < worker.size() && j < work.size()) {
            if (worker[i] >= work[j].first) {
                ans += work[j].second;
                ++i;
            } else {
                ++j;
            }
        }
        
        return ans;
    }
};