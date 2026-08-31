class Solution {
   public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start) {
        // if()
        res.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates if they are at the same depth
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};

// sort + backtrack
