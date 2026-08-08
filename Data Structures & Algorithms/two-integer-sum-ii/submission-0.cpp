class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size()) - 1;

        while (left < right) {
            int curr_sum = numbers[left] + numbers[right];

            if (curr_sum == target) {
                return {left + 1, right + 1};
            } 
            else if (curr_sum > target) {
                --right;
            } 
            else {
                ++left;
            }
        }

        return {};
    }
};

/**

## Clarification

1. Is the input array sorted in ascending order?
2. Are the returned indices 1-based?
3. Is there guaranteed to be exactly one valid solution?

## Brute Force

Check every pair of numbers.

- Time: `O(n²)`
- Space: `O(1)`

## Optimized Approach

Since the array is sorted, use two pointers.

- `left` starts from the beginning.
- `right` starts from the end.
- If the current sum is greater than the target, move `right` left.
- If the current sum is smaller than the target, move `left` right.
- If the sum equals the target, return the two 1-based indices.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Edge Cases

1. Negative numbers
2. Duplicate values
3. The valid pair is at the two ends

## Interview Explanation

Since the input array is sorted, I can use two pointers.

I start one pointer at the beginning and the other at the end.

If the current sum is too large, I move the right pointer left to decrease the sum.
If the sum is too small, I move the left pointer right to increase the sum.

When the sum matches the target, I return the two indices.

The time complexity is O(n) and the space complexity is O(1).

## Follow-up
Why does the two-pointer strategy work only because the array is sorted?

The two-pointer strategy works because the array is sorted.
If the current sum is greater than the target, I move the right pointer to the left because that gives me a smaller value and decreases the sum.
If the current sum is smaller than the target, I move the left pointer to the right because that gives me a larger value and increases the sum.
Without sorting, moving a pointer does not guarantee whether the sum will increase or decrease.
In that case, I can use a hash table to check whether target - nums[i] has already been seen. This takes O(n) average time and O(n) extra space.

## Note
instead of vector<int> res; directly using {}

**/