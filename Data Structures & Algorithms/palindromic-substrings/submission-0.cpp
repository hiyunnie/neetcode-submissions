class Solution {
   public:
    int count = 0;
    string palindrome(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
        }
        return count;
    }
};
