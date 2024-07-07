class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int Q = 0, R = 0, d = 0, e = 0, ans = 0;
        while(numBottles) {
            Q = numBottles / numExchange, R = numBottles % numExchange;
            if (!Q && R) 
                d = R;
            else
                d = Q * numExchange;
            e = Q;
            numBottles = numBottles - d + e;
            ans += d;
        }
        return ans;
    }
};