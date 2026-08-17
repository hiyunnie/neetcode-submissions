class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp[n + 1];
        // Base Cases
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        // 狀態轉移方程式
        return dp[n];
    }
};
// 因為要到達第 n 階，一定要麼從 n - 1 階跨一步過來，要麼從 n - 2 階跨兩步過來（沒有別的路了）
