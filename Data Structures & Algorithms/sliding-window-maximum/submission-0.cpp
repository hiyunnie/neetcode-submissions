class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;  // val,index
        vector<int> res;
        int l = 0;
        int r = l + k - 1;
        for (int i = 0; i < k; i++) {
            maxHeap.push({nums[i], i});
        }
        int maxVal = maxHeap.top().first;
        res.push_back(maxVal);

        while (r + 1 < nums.size()) {
            r++;
            maxHeap.push({nums[r], r});
            l++;

            while (!maxHeap.empty() && maxHeap.top().second < l) {
                maxHeap.pop();
            }

            maxVal = maxHeap.top().first;
            res.push_back(maxVal);
        }
        return res;
    }
};