class Solution {
   public:
    void backtrack(vector<int>& nums, int target, int start, vector<int>& path,
                   vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target) continue;
            path.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, path, res);
        return res;
    }
};



/**

## Clarification

- Can each number be used unlimited times?
- Are all candidates positive?
- Are the input values unique?

## Optimized Approach

Use backtracking after sorting the candidates.

`path` stores the current combination.

`start` controls where the next search begins so that combinations are generated in non-decreasing order.

For example:

`[2,2,3]`

is generated, but:

`[2,3,2]`
`[3,2,2]`

are not generated again.

For each candidate:

1. Add it to `path`.
2. Subtract it from the remaining target.
3. Recursively continue from index `i` because the same number can be reused.
4. Remove it from `path` after returning.

If `target == 0`, add the current path to the result.

Because the array is sorted, if `nums[i] > target`, we can stop the loop early.

## Complexity

Let `T` be the target and `m` be the smallest candidate.

Maximum recursion depth is about:

`T / m`

The total time depends on how many valid and invalid combinations are explored, so backtracking is exponential in the worst case.

- Time: exponential
- Space: `O(T / m)` for the recursion stack and current path, excluding output

## Interview Explanation

I use backtracking to build combinations.

I sort the candidates first so I can stop early when a number is larger than the remaining target.

The `start` index prevents generating the same combination in different orders.

I pass `i` instead of `i + 1` in the recursive call because each candidate can be reused multiple times.

When the remaining target becomes zero, I add the current path to the result.

## Follow-up

What would change if each candidate could only be used once?

If each candidate can only be used once, I move to i + 1 in the recursive call. If the input contains duplicate values, I also skip equal candidates at the same recursion level to avoid duplicate combinations.

class Solution {
   public:
    void backtrack(vector<int>& nums, int target, int start, vector<int>& path,
                   vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target) continue;
            path.push_back(nums[i]);
            backtrack(nums, target - nums[i], i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, path, res);
        return res;
    }
};

## Note
[2, 2, 3]、[2, 3, 2]  [3, 2, 2]
only count once

**/