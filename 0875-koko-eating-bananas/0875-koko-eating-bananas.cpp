class Solution {
public:
    bool isValid(vector<int>&piles, int h, int minBananas) {
        long long hours = 0;
        for(int pile : piles) {
            hours += pile / minBananas;
            if (pile%minBananas > 0)
                ++hours;
        }
        if(hours <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;
        for(int pile : piles)
            high = max(high, pile);
        
        int k = 0;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (isValid(piles, h, mid)) {
                k = min(high, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return k;
    }
};