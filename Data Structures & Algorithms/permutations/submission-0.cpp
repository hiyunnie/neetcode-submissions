class Solution {
   public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> used;
    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return res;
    }
};
