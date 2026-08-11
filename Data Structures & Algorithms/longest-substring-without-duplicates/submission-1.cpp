class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash_set;
        int left = 0, max_len = 0;
        for (int right = 0; right < s.length(); right++) {
            while (hash_set.count(s[right])) {
                hash_set.erase(s[left]);
                left++;
            }
            hash_set.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

/**

## Clarification

- Can the string contain spaces or symbols?
- Is the comparison case-sensitive?
- Can the input string be empty?

## Brute Force

Check every substring and determine whether it contains duplicate characters.

- Time: `O(n^3)` for a straightforward implementation
- Space: `O(n)`

## Optimized Approach

Use a sliding window with two pointers.

`left` and `right` represent the boundaries of the current window.

Use an `unordered_set` to store the characters currently inside the window.

For each `right`:

1. If `s[right]` is already in the set, move `left` forward and remove characters until the duplicate is gone.
2. Insert `s[right]` into the set.
3. Update the maximum window length.

## Complexity

- Time: `O(n)`
- Space: `O(min(n, character_set_size))`

If the character set is fixed, such as ASCII, the space can be considered `O(1)`.

## Edge Cases

1. Empty string
2. All characters are the same, such as `"aaaa"`
3. All characters are unique, such as `"abcdef"`

## Interview Explanation
I use a sliding window with two pointers.
The hash set stores all characters currently inside the window.
When the right pointer reaches a duplicate character, I move the left pointer forward and remove characters from the set until the duplicate is removed.
Then I add the current character and update the maximum window length.
Each character is inserted and removed at most once, so the time complexity is O(n).

## Follow-up
Can you optimize this solution so that left does not move one character at a time?


## Follow-up
Can you optimize this solution so that left does not move one character at a time?
Time: O(n) average
Space: O(n) worst case

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

## Note


**/
