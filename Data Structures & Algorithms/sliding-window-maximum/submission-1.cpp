class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;  // val,index
        vector<int> res;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            maxHeap.push({nums[r], r});

            // 當視窗大小達到 k 時，開始記錄結果
            if (r >= k - 1) {
                int l = r - k + 1;  // 當前視窗的左邊界

                // 移除不在視窗內的過期元素
                while (!maxHeap.empty() && maxHeap.top().second < l) {
                    maxHeap.pop();
                }

                res.push_back(maxHeap.top().first);
            }
        }
        return res;
    }
};