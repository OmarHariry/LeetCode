class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), 
            [](const vector<int>&a, const vector<int>&b) {
                double d1 = sqrt(pow(a[0], 2) + pow(a[1], 2));
                double d2 = sqrt(pow(b[0], 2) + pow(b[1], 2));
                
                return d1 < d2;
            });
        
        return vector<vector<int>> (points.begin() , points.begin()+ k);
    }
};