class Solution {
   public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<int> path, int start) {
        res.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            
            path.push_back(nums[i]);
            backtrack(nums, path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, path, 0);
        return res;
    }
};
