class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (const string& str : strs) {
            int len = str.size();
            res += to_string(len) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            // ex. 120#helloolelelel..
            // 解析長度 len（將 '#' 前面的數字字串轉成 int）
            int len = stoi(s.substr(i, j - i));

            string temp = s.substr(j + 1, len);
            res.push_back(temp);

            i = j + 1 + len;
        }

        return res;
    }
};

/**

## Clarification

- Can strings contain `#`?
- Can strings be empty?
- Can strings contain digits or special characters?

## Optimized Approach

Use length-prefix encoding.
For each string, encode it as:
`length + "#" + string`
Example:
`["hello", "abc"]`
becomes:
`5#hello3#abc`
During decoding:

1. Find `#`.
2. Parse the number before `#` as the string length.
3. Read exactly `len` characters after `#`.
4. Move to the next encoded string.

Because the decoder knows the exact length, the original string can contain `#`, digits, or other characters.

## Complexity

Let `N` be the total number of characters in all strings.

- Encode Time: `O(N)`
- Decode Time: `O(N)`
- Space: `O(N)`

The output itself requires O(N) space.

## Edge Cases

1. Empty string: `""`
2. String containing `#`
3. String containing numbers
4. Multiple empty strings
5. Long string length with multiple digits

## Interview Explanation

I use length-prefix encoding.
For each string, I store its length followed by a delimiter and then the original string.
During decoding, I first find the delimiter and parse the length. Then I read exactly that many characters.
This avoids ambiguity even if the original string contains the delimiter itself.

## Follow-up
Why is using only a delimiter, such as joining strings with `#`, not sufficient?

Using only a delimiter is not sufficient because the original string may also contain the delimiter. Then the decoder cannot distinguish between a separator and a character that belongs to the string.

## Note

Example:
`["a#b", "hello"]`
Encode:
`3#a#b5#hello`
The decoder reads length 3 first, so `#` inside `"a#b"` does not cause a problem.

**/

