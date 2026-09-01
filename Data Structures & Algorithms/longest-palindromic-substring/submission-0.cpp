class Solution {
   public:
    string palindrome(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            // 以 s[i] 為中心的最長迴文串
            string s1 = palindrome(s, i, i);
            // 以 s[i] 和 s[i+1] 為中心的最長迴文串
            string s2 = palindrome(s, i, i + 1);

            // 更新最長結果
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }
};

// 中心擴展法或 DP