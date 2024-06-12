class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        vector<vector<int>>ans;
        
        while (i < n && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);
        
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        ans.push_back(newInterval);
        
        while (i < n)
            ans.push_back(intervals[i++]);
        
        return ans;
    }
};