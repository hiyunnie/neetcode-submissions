class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;

        // pair.first  = frequency
        // pair.second = number
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& entry : freq) {
            minHeap.push({entry.second, entry.first});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
/**

## Clarification
1. k = 0 return null array?
2. if number is distinct but k assigned. what vlaue should i return the biggest one?

## Brute Force

Use a hash map to count the frequency of each number.

Then sort all unique numbers by frequency and return the top `k`.

- Time: `O(n + m log m)`
- Space: `O(m)`

where `m` is the number of unique elements.

## Optimized Approach

Use a hash map to count frequencies.

Then maintain a min-heap of size `k`.

For each `(number, frequency)` pair:

1. Push `(frequency, number)` into the heap.
2. If the heap size is greater than `k`, remove the smallest frequency.
3. At the end, the heap contains the `k` most frequent elements.

- Time: `O(n + m log k)`
- Space: `O(m + k)`

## Implementation

## Edge Cases

## Interview Explanation

## Follow-up
Can you solve it in O(n) time without using a heap?

bucket[freq] = 所有出現 freq 次的 number

vector<vector<int>> bucket(5); // [[],[],[],[],[]]
bucket[0] = []
bucket[1] = [3]
bucket[2] = [2]
bucket[3] = [1]
bucket[4] = []
bucket[5] = []
for (int num : bucket[freq]) 遇到空的會自動跳過

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // 1. count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // bucket[f] = numbers that appear f times
        vector<vector<int>> bucket(nums.size() + 1);

        // 2. put numbers into buckets
        for (const auto& entry : freq) {
            int num = entry.first;
            int count = entry.second;

            bucket[count].push_back(num);
        }

        // 3. collect from highest frequency
        vector<int> res;

        for (int freq = nums.size(); freq >= 1; --freq) {
            for (int num : bucket[freq]) { // bucket[4] = [] 遇到空的會自動跳過
                res.push_back(num);

                if (res.size() == k) {
                    return res;
                }
            }
        }
    }
};

## Note


**/
