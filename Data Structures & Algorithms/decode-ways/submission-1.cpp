class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0); // dp[i] 代表：字串 s 的前 i 個字元，總共有幾種合法的解碼方法數。
        // base case
        dp[0] = 1;                      // 空字串
        dp[1] = (s[0] != '0') ? 1 : 0;  // 第一個字元如果不為 '0' 則有 1 種可能

        // xxxx2
        for (int i = 2; i <= n; i++) {
            int one_digit = s[i - 1] - '0';
            int two_digits = (s[i - 2] - '0') * 10 + one_digit;
            if (one_digit >= 1 && one_digit <= 9) {
                dp[i] += dp[i - 1];
            }
            if (two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};