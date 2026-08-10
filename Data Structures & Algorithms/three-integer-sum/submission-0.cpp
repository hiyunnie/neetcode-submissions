class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0, left = 0, right = 0;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // follow up
            if (nums[i] > 0) {
                break;
            }
            // hint!!
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            target = -nums[i];
            left = i + 1;
            right = nums.size() - 1;

            while (left < right) {
                int curr_sum = nums[left] + nums[right];
                if (curr_sum > target) {
                    right--;
                } else if (curr_sum < target) {
                    left++;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // skip all duplicate
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

/**

## Brute Force

Check every combination of three numbers.

- Time: `O(n^3)`
- Space: `O(1)` excluding the result

## Optimized Approach

Sort the array first.

Then fix one number `nums[i]` and reduce the problem to Two Sum on the remaining right side.

For each `i`:

1. Set `target = -nums[i]`.
2. Use two pointers, `left = i + 1` and `right = n - 1`.
3. If the current sum is too large, move `right` left.
4. If the current sum is too small, move `left` right.
5. If a valid triplet is found, add it to the result and skip duplicate values.

Also skip duplicate values for `nums[i]` to avoid duplicate triplets.

## Complexity

- Time: `O(n^2)` O(nlogn) + O(n*n) ~= O(n*n)
- Space: `O(1)` excluding the sorting stack and output

## Implementation

## Edge Cases

## Interview Explanation

## Follow-up
1. Why do we only skip duplicates after finding a valid triplet, instead of skipping duplicates
every time we move left or right? code implement already

2. After sorting, can you add an early-exit optimization to reduce unnecessary work?
// follow up
if (nums[i] > 0) {
    break;
}
## Note


**/