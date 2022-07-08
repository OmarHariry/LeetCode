class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e9;
        vector<int> dp_(m * (n + 1) * (target + 1), INF);
        auto dp = [&](int i, int j, int k) -> int& {
            return dp_[i * (n + 1) * (target + 1) + j * (target + 1) + k];  
        };
        if (houses[0] == 0) {
            for (int i = 1; i <= n; i++) {
                dp(0, i, 1) = cost[0][i - 1];
            }
        } else dp(0, houses[0], 1) = 0;
        for (int i = 1; i < m; i++)  {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= target; k++) {
                    if (houses[i] != 0 and houses[i] != j) continue;
                    int c = (houses[i] == j ? 0 : cost[i][j - 1]);
                    dp(i, j, k) = dp(i - 1, j, k) + c;
                    for (int p = 1; p <= n; p++) {
                        if (p != j) {
                            dp(i, j, k) = min(dp(i, j, k), dp(i - 1, p, k - 1) + c);
                        }
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp(m - 1, i, target));
        }
        return (ans == INF ? -1 : ans);
    }
};