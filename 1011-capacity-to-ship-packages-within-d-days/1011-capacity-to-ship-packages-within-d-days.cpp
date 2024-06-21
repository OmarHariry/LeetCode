class Solution {
public:
    bool isValid(vector<int>&weights, int days, int capacity) {
        int load = 0, minDays = 1;
        for(int w : weights) {
            if (load + w > capacity) {
                minDays++;
                load = w;
            } else
                load += w;
        }
        return minDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        int shipCapacity = 0;
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(isValid(weights, days, mid)) {
                shipCapacity = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return shipCapacity;
    }
};