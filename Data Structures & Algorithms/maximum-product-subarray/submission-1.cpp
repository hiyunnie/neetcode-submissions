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
貪婪
maxProduct
curProduct 如果curr_sum==0的話重新subarray


## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Interview Explanation

## Follow-up

## Note
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