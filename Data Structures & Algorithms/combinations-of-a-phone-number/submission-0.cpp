class Solution {
private:
    const vector<string> phoneMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> res;
    string path;

    void backtrack(const string& digits, int index) {
        // 1. 終止條件：處理完所有數字
        if (index == digits.size()) {
            res.push_back(path);
            return;
        }

        // 2. 拿到當前數字對應的字母字串
        string letters = phoneMap[digits[index] - '0'];

        // 3. 遍歷當前數字的所有可能字母
        for (char c : letters) {
            path.push_back(c);
            backtrack(digits, index + 1); // 探索下一個數字
            path.pop_back();              // 撤銷選擇
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack(digits, 0);
        return res;
    }
};