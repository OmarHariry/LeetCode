#include<vector>
class Solution {
public:
    /*int climbStairs(int n) {
    normal recursive 
    Time O(2^N)
    space O(n)
		if (n <= 1) return 1;
		if (n == 2)return 2;
		return climbStairs(n - 1) + climbStairs(n - 2);
	}*/
    /*
    int climbStairs(int n) {
    vector<int>arr(n + 1);
		if (n == 1)
			return 1;
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		for (int i = 3; i <=n;++i) {
			arr[i] = arr[i - 2] + arr[i - 1];

		}
		return arr.back();}*/
    
	int climbStairs(int n) {
		vector<int>dp(n + 1, -1);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};