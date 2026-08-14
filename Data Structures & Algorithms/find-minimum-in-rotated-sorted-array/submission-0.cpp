class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // 2. 當 l == r 時跳出迴圈，此時 l (或 r) 就是最小值的索引
        while (l < r) {
            int m = l + (r - l) / 2;

            // 3. 以最右邊的 nums[r] 作為基準進行比較
            if (nums[m] > nums[r]) {
                // 中間值大於右邊，說明最小值在 m 的右側 (不包含 m)
                l = m + 1;
            } else {
                // 中間值小於等於右邊，說明最小值可能是 m 本身，或在 m 的左側
                r = m;
            }
        }

        return nums[l];
    }
};
/**
## Approach

Use binary search.

Compare `nums[mid]` with `nums[right]`.

- If `nums[mid] > nums[right]`,
  the minimum must be on the right side of `mid`.

  `left = mid + 1`

- Otherwise,
  the minimum could be `mid` itself or somewhere on the left side.

  `right = mid`

Continue until `left == right`.

That index is the minimum element.

## Complexity

- Time: `O(log n)`
- Space: `O(1)`

## Interview Explanation

I use binary search and compare the middle value with the rightmost value.
If `nums[mid]` is greater than `nums[right]`, the minimum must be to the right of `mid`.
Otherwise, the minimum is either `mid` itself or somewhere to the left, so I keep `mid` in the search range.
When `left == right`, that position is the minimum.

## Follow-up

What changes if the rotated sorted array can contain duplicate values?


## Note
將 nums[m] 與 nums[l] 比對在某些極端情況（例如完全沒旋轉的陣列 [1, 2, 3]）會判斷錯誤。
最佳做法： 永遠拿 nums[m] 與最右邊的 nums[r] 做比較
當 l == r 時，該位置就是最小值的索引！
**/