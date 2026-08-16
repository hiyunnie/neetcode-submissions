class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], cur_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (cur_sum < 0) cur_sum = nums[i];
            else cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};
/**

## Approach

Use Kadane's Algorithm.

Keep track of:

- `cur_sum`: the maximum subarray sum ending at the current position
- `max_sum`: the maximum subarray sum found so far

For each number:

- If the previous `cur_sum` is negative, discard it and start a new subarray from the current number.
- Otherwise, extend the current subarray.

Then update `max_sum`.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Interview Explanation

I use Kadane's Algorithm.

If the current accumulated sum becomes negative, keeping it would only decrease the sum of any future subarray, so I discard it and start a new subarray from the current element.

Otherwise, I extend the current subarray.

I update the maximum sum at every position.

The time complexity is O(n) and the extra space is O(1).

## Follow-up

Can you also return the start and end indices of the maximum subarray?
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int maxSum = nums[0];

        int currentStart = 0;
        int bestStart = 0;
        int bestEnd = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (curSum < 0) {
                curSum = nums[i];
                currentStart = i;
            } else {
                curSum += nums[i];
            }

            if (curSum > maxSum) {
                maxSum = curSum;
                bestStart = currentStart;
                bestEnd = i;
            }
        }

        return {bestStart, bestEnd};
    }
};
## Note

Key idea:

If `cur_sum < 0`, carrying it forward can never help a future subarray.

(總和)
   9 |                                                8 (最高點 ★)
   8 |                                               /
   7 |                                              /
   6 |                                             /
   5 |                                 5          /
   4 |                     4          / \        /
   3 |                    / \        /   \      /
   2 |   2               /   2      /     4----/
   1 |  / \             /     \    /
   0 |-------------------------------------------------- (歸零基準線)
  -1 |     -1 (棄用)   /
  -2 |
     +--------------------------------------------------
數字:    [2]  [-3]    [4]   [-2]   [2]   [1]  [-1]   [4]
步驟:     1    2       3      4     5     6    7      8

**/
