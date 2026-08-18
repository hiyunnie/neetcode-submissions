class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // 因為貪婪法「只看當下」，而 DP 會考慮所有可能，並記錄達到各個小金額所需的最少硬幣數

        // 初始化：陣列大小 amount + 1，預設值給 amount + 1（代表無限大）
        vector<int> dp(amount + 1, amount + 1);  // 湊出金額 i 所需的最少硬幣數 !!!

        // base case : 湊 0 元需要 0 枚硬幣
        dp[0] = 0;

        // status function:
        // 假設你已經站在最終目標的面前。列出所有可能的「最後選擇」，並用取最值/加總結合
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i - c >= 0) {  // 代表可以用這枚硬幣
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        // 如果 dp[amount] 還是初始值，代表湊不出來，回傳 -1
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
