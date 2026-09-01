class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        // dp[j]: 表示目標總和為 j 時，是否能湊出該總和
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; j--)  // 必須從大到小倒序！
            {
                dp[j] = dp[j] || dp[j - num];
                // 不選當前數字 vs. 選當前數字 (如果之前能湊出j-num的話那現在加上num之後就一定湊出總和j)
                // 
            }
        }
        return dp[target];
    }
};
// 0/1 背包問題: 拿 or 不拿 讓他總和是sum(nums)/2