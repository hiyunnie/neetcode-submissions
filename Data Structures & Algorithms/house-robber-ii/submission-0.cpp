class Solution {
   private:
    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int current = max(prev1, prev2 + nums[i]);  // current = dp[i]
            prev2 = prev1;                              // prev2=dp[i-2]
            prev1 = current;                            // prev1=dp[i-1]
        }
        return prev1;
    }

   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // 情況 1：搶 0 到 n-2
        // 情況 2：搶 1 到 n-1
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};