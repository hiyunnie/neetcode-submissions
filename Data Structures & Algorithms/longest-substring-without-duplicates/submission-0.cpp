/*
## Follow-up
Can you optimize this solution so that left does not move one character at a time?

*/
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_map;
        int left = 0, max_len = 0;
        for (int right = 0; right < s.length(); right++) {
            if (hash_map.count(s[right])) {
                left = max(left, hash_map[s[right]] + 1);
            }
            hash_map[s[right]] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
