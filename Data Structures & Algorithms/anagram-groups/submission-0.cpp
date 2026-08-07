class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for (string str : strs) {
            string curr = str;
            sort(curr.begin(), curr.end());
            auto it = umap.find(curr);
            if (it != umap.end()) {
                // found
                it->second.push_back(str);
            } else {
                umap[curr].push_back(str);
            }
        }
        for (auto& pair : umap) {
            res.push_back(pair.second);
        }
        return res;
    }
};

/**

## Clarification
- Are all characters lowercase English letters?
- Is the comparison case-sensitive?
- Can the input contain empty strings?

## Brute Force
For each string, compare it with every other string and check whether
they are anagrams.

To check whether two strings are anagrams, sort both strings and compare them.

- Time: approximately `O(n * n * k log k)`
- Space: depends on the sorting implementation

## Optimized Approach

Use a hash table where:

- key = sorted version of the string
- value = all original strings that have the same sorted form

For each string:
1. Copy the string.
2. Sort the copied string to generate a key.
3. Append the original string to `umap[key]`.

Finally, iterate through the hash table and push each group into the result.

## Complexity
- Time: `O(n)` (wrong)
- Space: `O(n)` (wrong)

每個 string 排序：O(k log k)
共 n 個 string
Time = O(n * k log k)
因為 hash map 裡面會存排序後的 key 和原字串：
Space = O(n * k)

## Implementation

## Edge Cases
1. Empty string: `[""]`
2. Single string: `["abc"]`
3. Multiple identical strings: `["abc", "abc"]`

## Interview Explanation
My approach is to use a hash table.
For each string, I sort its characters and use the sorted string as the key.
All anagrams will produce the same key, so I append the original string to the corresponding vector.
After processing all strings, I collect all vectors from the hash table into the result.
If there are n strings and each string has length k, the time complexity is O(n * k log k), and the space complexity is O(n * k).

## Follow-up
Can you improve the time complexity if the input contains only lowercase English letters?

提示只給你一點：
不一定要 sort
可以想想：26 個字母的 frequency 能不能當 key？

I use a fixed-size array of 26 integers to count the frequency of each character. Then I encode the frequency array into a string and use that string as the hash map key.

Time: O(n * k)
Space: O(n * k)


class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;

        for (const string& str : strs) {
            array<int, 26> freq{};
            for (char c : str) {
                freq[c - 'a']++;
            }
            string key;
            for (int count : freq) {
                key += "#" + to_string(count);
            }
            umap[key].push_back(str);
        }
        for (auto& entry : umap) {
            res.push_back(entry.second);
        }
        return res;
    }
};

## Note
1.
// umap 本身是 Map 物件，沒有 .second 屬性（Iterator 才有）。
// 迴圈內沒有對 umap 做 erase 或修改，這會導致無窮迴圈 (Infinite Loop)。
while(!umap.empty())
{
    res.push_back(umap.second);
}
2.
其實這裡甚至不用 find()：
umap[key].push_back(str);
如果 key 不存在，operator[] 會自動建立一個空的 vector<string>。
**/
