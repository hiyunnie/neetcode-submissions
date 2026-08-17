class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int dp[n];
        // base case
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
// 當你走到最後一家房子（第 i 家）時，你只需要知道：前一家（第 i - 1
// 家）能搶到的最高金額。前兩家（第 i - 2 家）能搶到的最高金額。

// 當你在考慮第 i 家要不要搶時，你只受「第 i -
// 1 家有沒有被搶」這個限制影響，你不需要知道更前面（第 1,
// 2 家）當初具體是用什麼順序搶的。

// 要求「最大 /最小 /幾種走法」 發現選擇之間有連帶限制（例如：不能選相鄰、每次只能走 1 或 2
// 步）大目標可以拆成「選這個」或「不選這個」的子問題比較

// // 不搶
// dp[i - 1]

// // 搶
// dp[i - 2] + nums[i]