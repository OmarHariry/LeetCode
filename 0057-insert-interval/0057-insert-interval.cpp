class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        // insert newInterval
        intervals.push_back(newInterval);
        // sort intervals
        sort(intervals.begin(), intervals.end());
        
        // merge overlapping intervals
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i) {
            if (ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        // O(nlogn)
        return ans;
    }
};