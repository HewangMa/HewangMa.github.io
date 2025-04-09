#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        vector<vector<int>> dp(n, vector<int>{0, 0});
        // dp[i][0] 表示第i天持有股票所能获得的最大利润
        // dp[i][1] 表示第i天不持有股票所能获得的最大利润
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[n - 1][1];
    }
};