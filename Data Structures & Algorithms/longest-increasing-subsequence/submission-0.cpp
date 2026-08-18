class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] 代表：「以 nums[i] 為結尾的最長遞增子序列長度」。
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
