class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int l = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> target;

        for (char v : t) {
            target[v]++;
        }

        int need = target.size();
        int have = 0;
        int min_len = INT_MAX;
        int start_idx = 0;
        
        for (int r = 0; r < s.size(); r++) {
            char curr = s[r];
            window[curr]++;
            if (target.count(curr) && (window[curr] == target[curr])) {
                // 該種類達到預期數量了
                have++;
            }
            // 縮左邊界直到不符合
            while (have == need) {  // 完全達成
                // 更新最短符合條件的子字串範圍
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }

                char left_char = s[l];
                window[left_char]--;
                if (target.count(left_char) && window[left_char] < target[left_char]) {
                    have--;
                }

                l++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};
