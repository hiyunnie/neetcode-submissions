class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0;
        vector<int> arr(26, 0);
        int max_cnt = 0;  // 我們截至目前為止，看過單一字母出現的最多次數
        int max_len = 0;
        for (int r = 0; r < s.size(); r++) {
            arr[s[r] - 'A']++;
            max_cnt = max(max_cnt, arr[s[r] - 'A']);

            while ((r - l + 1) - max_cnt > k) {
                arr[s[l] - 'A']--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
// 這題是用sloding window
// r for loop move 會有一個arr[26]來記錄目前windows裡面有多少letters 也會有個int max_len (update
// each time max(max_len,r-l)) l 是當arr[26]裡面的non zero letter數目都已經>k
// (l就要一路move直到有letter數目=k)

// 目前的窗口內（長度為 r - l + 1）
// 「需要被替換掉的字元數量」= 窗口總長度 - 最多字元的出現次數。
// 只要 (r - l + 1) - max_count <= k，這個窗口就是合法的！

// 要讓窗口變得比之前記錄到的答案更長，我們必須找到一個更大的 max_cnt！

// 如果縮小窗口時 max_cnt 變小了，那當前窗口的長度只會比歷史紀錄更小，絕對不可能刷新 max_len
// 的紀錄。