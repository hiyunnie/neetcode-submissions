class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(curMax, curMin);
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);
            maxProduct = max(maxProduct, curMax);
        }
        return maxProduct;
    }
};
/**

## Approach

Use a modified Kadane's Algorithm.

For each position, keep:

- `curMax`: maximum product ending at the current index
- `curMin`: minimum product ending at the current index

We need both because multiplying by a negative number can turn the minimum product into the maximum product.

If the current number is negative, swap `curMax` and `curMin`.

Then decide whether to:

- start a new subarray from the current number
- extend the previous subarray

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Interview Explanation

I keep both the maximum and minimum product ending at the current position.

The minimum is important because a negative value multiplied by another negative number can become the maximum product.

If the current number is negative, I swap the current maximum and minimum.

Then I update both states and keep track of the global maximum.

## Note
wrong:
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], curProduct = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (curProduct == 0)
                curProduct = nums[i];
            else
                curProduct *= nums[i];
            maxProduct = max(maxProduct, curProduct);
        }
        return maxProduct;
    }
};
nums=[3,-1,4]  Expected output: 4
**/