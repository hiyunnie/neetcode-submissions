class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] 代表：字串 s 的前 i 個字元，是否能被字典裡的單字拼出來（true / false）。
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[0] = true;  // 空字串;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // 只要找到一種切法就可以跳出內層迴圈
                }
            }
        }
        return dp[n];
    }
};

// [桶子 Bucket 0] -> (空)
// [桶子 Bucket 1] -> ["code"] -> nullptr
// [桶子 Bucket 2] -> (空)
// [桶子 Bucket 3] -> ["neet"] -> nullptr

// 圖解流程（以 $i = 8$ 走到最後為例）假設前面已經算好 dp[4] = true（代表 "neet" 拼成功了）：
// 字串 s 的索引：   0   1   2   3   4   5   6   7
// 字串內容：       [n   e   e   t] [c   o   d   e]
//                                 ▲               ▲
//                                 j               i
//                                (4)             (8)