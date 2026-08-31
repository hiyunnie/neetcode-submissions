class Solution {
   public:
    vector<string> path;
    vector<vector<string>> res;
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void backtrack(string& s, int start) {
        // 終止條件：指針走到字串末尾，代表找到一組完全由回文組成的切割方式
        if (start == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            // 先提取當前要切割的子字串 s[start...i]
            string sub = s.substr(start, i - start + 1);

            // 剪枝條件：只有當「當前切下來的子字串是回文」時，才繼續向下遞迴
            if (isPalindrome(sub)) {
                path.push_back(sub);
                backtrack(s, i + 1);  // 探索下一個位置
                path.pop_back();      // 撤銷選擇
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};

/*
                        [] (start = 0)
            ┌────────────┼────────────┐
            │ "a"        │ "aa"       │ "aab"
            ▼            ▼            ▼
          ["a"]        ["aa"]       ["aab"] (非回文! 觸發 return)
            │            │            X (直接剪枝，不向下探索)
            ▼            ▼
          ["a", "a"]   ["aa", "b"]
            │
            ▼
        ["a", "a", "b"]

*/
