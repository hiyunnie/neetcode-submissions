class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[left] <= nums[mid])  // left side is sorted
            {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[right] >= nums[mid])  // right side is sorted
            {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
/**

## Clarification

- Are all elements unique?
- Is the array originally sorted in ascending order and then rotated?
- Should I return `-1` if the target does not exist?

## Brute Force

Scan through the array and compare each element with the target.

- Time: `O(n)`
- Space: `O(1)`

## Optimized Approach

Use binary search.

Because the array is sorted and then rotated, at least one side of `mid` is always sorted.

1. If `nums[mid] == target`, return `mid`.
2. Check whether the left half is sorted.
3. If the target is inside the sorted left half, search left.
4. Otherwise, search right.
5. If the left half is not sorted, then the right half must be sorted.
6. Check whether the target is inside the sorted right half and update the search range.

## Complexity

- Time: `O(log n)`
- Space: `O(1)`

## Edge Cases

1. Single element
2. Target does not exist
3. Array is not rotated
4. Target is at `left` or `right`

## Interview Explanation

I use binary search.

Since the array was originally sorted and then rotated, at least one half around the middle element is still sorted.

First, I determine which half is sorted.

Then I check whether the target is inside that sorted range. If it is, I continue searching that half. Otherwise, I search the other half.

This reduces the search range by half each time, so the time complexity is O(log n).

## Follow-up

What changes if the array can contain duplicate values?
report first number index?

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                index = mid;
                right = mid-1;
                continue;
            }
            // [1, 0, 1, 1, 1]
            // Cannot determine which side is sorted
            if (nums[left] == nums[mid] &&
                nums[mid] == nums[right]) {
                ++left;
                --right;
                continue;
            }

            if (nums[left] <= nums[mid])  // left side is sorted
            {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[right] >= nums[mid])  // right side is sorted
            {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return index;
    }
};
## Note

Use:

`nums[left] <= nums[mid]`

instead of:

`nums[left] < nums[mid]`

because `left` can be equal to `mid`.

**/